/**
 * @copyright Copyright © 2020 SetHashTable. All rights reserved.
 *
 * @license{<blockquote>
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * * Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 * </blockquote>}
 *
 * @author Famari Carlo                                                  <br>
 *         Electronic Engineer                                           <br>
 *         carlo.famari@gmail.com
 * @date April, 2020
 * @version v1.0
 */

#include "Store.hpp"
#include "Beverage.hpp"
#include "ElectronicDevice.hpp"
#include "Food.hpp"
#include "PersonalCareProduct.hpp"

using namespace set;

/**
 * @brief Constructor
 * @details Constructor with all fields
 * @param[in] n store name
 * @param[in] a store address
 * @param[in] c store capacity
 */
Store::Store(string n, string a, size_t c)
{
    _name           = n;
    _address        = a;
    _annual_revenue = 0;
    _collection     = new HashSetItem(c);
}

/**
 * @brief Constructor
 * @details Copy constructor
 * @param[in] store reference to Store to be copied
 */
Store::Store(Store& store)
{
    _name           = store._name;
    _address        = store._address;
    _annual_revenue = store._annual_revenue;
    size_t capacity = store._collection->getCapacity();
    _collection     = new HashSetItem(capacity);
    for (size_t i = 0; i < capacity; i++)
    {
        _collection->insertItemLP(store._collection->get(i)->key,
                                  store._collection->get(i)->value);
    }
}

/**
 * @brief Destructor
 */
Store::~Store()
{
    delete _collection;
}

/**
 * @brief Gets name of this
 * @details Getter method for field _name
 * @return name
 */
string Store::getName() const
{
    return _name;
}

/**
 * @brief Sets name of this
 * @details Setter method for field _name
 * @param[in] n store name
 */
void Store::setName(string n)
{
    _name = n;
}

/**
 * @brief Gets address of this
 * @details Getter method for field _address
 * @return address
 */
string Store::getAddress() const
{
    return _address;
}

/**
 * @brief Sets address of this
 * @details Setter method for field _address
 * @param[in] a store address
 */
void Store::setAddress(string a)
{
    _address = a;
}

/**
 * @brief Gets annual revenue of this
 * @details Getter method for field _annual_revenue
 * @return annual revenue
 */
size_t Store::getAnnualRevenue() const
{
    return _annual_revenue;
}

/**
 * @brief Sets annual revenue of this
 * @details Setter method for field _annual_revenue
 * @param[in] r store annual revenue
 */
void Store::setAnnualRevenue(size_t r)
{
    if (r < 0)
    {
        _annual_revenue = 0;
    }
    else
    {
        _annual_revenue = r;
    }
}

/**
 * @brief Prints information on a string
 * @details A string with information of all items of the store is built.
 * @return information string
 * @remarks This method uses standard for loop to print items
 */
string Store::sprintItems()
{
    return _collection->sprint();
}

/**
 * @brief Prints information on a string
 * @details A string with information of all items of the store is built.
 * @return information string
 * @remarks This method uses for range loop to print items, for Iterator
 * testing purpose.
 */
string Store::sprintAll()
{
    string result  = "ITEMS\n\n";
    size_t counter = 0;

    for (HashNode<size_t, Item*> node : *_collection)
    {
        if (!_collection->isAvailable(counter++))
        {
            result += "KEY: " + to_string(node.key) + "\n" +
                node.value->sprint() + "\n\n";
        }
    }
    result += "\n";

    return result;
}

/**
 * @brief Prints information on a string with selection
 * @details A string with information of all items of the store is built.
 * The string is divided by category.
 * @return information string
 * @remarks This method uses for range loop to print items.
 */
string Store::sprintItemsOf()
{
    string result      = "Print by category\n";
    string result_ed   = "\nELECTRONIC DEVICES\n\n";
    string result_food = "\nFOOD\n\n";
    string result_bev  = "\nBEVERAGES\n\n";
    string result_pcp  = "\nPERSONAL CARE PRODUCTS\n\n";

    for (auto node : *_collection)
    {
        Item* item = node.value;
        if (dynamic_cast<ElectronicDevice*>(item) != nullptr)
        {
            result_ed += item->sprint() + "\n\n";
        }
        else if (dynamic_cast<Food*>(item) != nullptr)
        {
            result_food += item->sprint() + "\n\n";
        }
        else if (dynamic_cast<Beverage*>(item) != nullptr)
        {
            result_bev += item->sprint() + "\n\n";
        }
        else if (dynamic_cast<PersonalCareProduct*>(item) != nullptr)
        {
            result_pcp += item->sprint() + "\n\n";
        }
    }

    return result + "-------------------" + result_ed + "-------------------" +
        result_food + "-------------------" + result_bev +
        "-------------------" + result_pcp + "-------------------";
}

/**
 * @brief Gets size of this
 * @details Total number of items of the store is calculated.
 * @return items number
 */
size_t Store::getItemsNumber() const
{
    return _collection->size();
}

/**
 * @brief Prints stock information on a string
 * @details A string with stock number information for all category of
 * product is built.
 * @return information string
 * @remarks This method uses for range loop to print items.
 */
string Store::sprintCategoryStock()
{
    size_t count_ed   = 0;
    size_t count_food = 0;
    size_t count_bev  = 0;
    size_t count_pcp  = 0;

    for (auto node : *_collection)
    {
        if (dynamic_cast<ElectronicDevice*>(node.value) != nullptr)
        {
            count_ed++;
        }
        else if (dynamic_cast<Food*>(node.value) != nullptr)
        {
            count_food++;
        }
        else if (dynamic_cast<Beverage*>(node.value) != nullptr)
        {
            count_bev++;
        }
        else if (dynamic_cast<PersonalCareProduct*>(node.value) != nullptr)
        {
            count_pcp++;
        }
    }
    string result = "\nPrint category stock\n";
    result += "ELECTRONIC DEVICES: " + to_string(count_ed) + "\n";
    result += "FOOD: " + to_string(count_food) + "\n";
    result += "BEVERAGES: " + to_string(count_bev) + "\n";
    result += "PERSONAL CARE PRODUCTS: " + to_string(count_pcp) + "\n";
    result += "\n";

    return result;
}

/**
 * @brief Adds an item to the store
 * @details A new item with its key is added to the store.
 * @param[in] k key
 * @param[in] item pointer to Item to insert with the given key
 * @remarks This method uses hash table insertion with Linear Probing
 * algorithm.
 */
void Store::addItem(size_t k, Item* item)
{
    _collection->insertItemLP(k, item);
}

/**
 * @brief Removes an item from the store
 * @details The item with given key is removed from the store.
 * @param[in] k key
 * @return pointer to removed Item
 * @remarks This method uses hash table removal with Linear Probing
 * algorithm.
 */
Item* Store::removeItem(size_t k)
{
    return _collection->removeItemLP(k);
}

/**
 * @brief Finds an item in the store
 * @details The item with given key is searched in the store.
 * @param[in] k key to search
 * @return pointer to Item found
 * @remarks This method uses hash table removal with Linear Probing
 * algorithm.
 */
Item* Store::findItem(size_t k)
{
    return _collection->findItemLP(k);
}

/**
 * @brief Updates an item in the store
 * @details The item with given key in the store is updated with new
 * parameters values.
 * @param[in] k item key to update
 * @param[in] b item brand
 * @param[in] m item model
 * @param[in] new_price item price
 * @param[in] on_discount item on discount flag
 * @param[in] new_stock item stock number
 */
void Store::updateItem(size_t k,
                       string b,
                       string m,
                       float  new_price,
                       bool   on_discount,
                       size_t new_stock)
{
    Item* item  = _collection->findItemLP(k);
    item->brand = b;
    item->model = m;
    item->setPrice(new_price);
    item->setOnDiscount(on_discount);
    item->setStock(new_stock);
    /*_collection->removeItem(k);
    Item* item = new Item(b, m, new_price, on_discount, new_stock);
    _collection->insertItemLP(k, item);*/
}

/**
 * @brief Gets stock number of this
 * @details Total number of stocked items of the store is calculated.
 * @return stock number
 */
size_t Store::totalStock()
{
    size_t  stocked    = 0;
    size_t* key_values = _collection->keys();

    for (size_t i = 0; i < getItemsNumber(); i++)
    {
        stocked += _collection->findItemLP(key_values[i])->getStock();
    }

    return stocked;
}
