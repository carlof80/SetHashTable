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

Store::Store()
{
    _name           = "Store";
    _annual_revenue = 0;
    _collection = new HashSetItem(100);
}

Store::Store(string n, string a, size_t c)
{
    _name           = n;
    _address        = a;
    _annual_revenue = 0;
    _collection     = new HashSetItem(c);
}

Store::Store(Store& store)
{
    _name           = store._name;
    _address        = store._address;
    _annual_revenue = store._annual_revenue;
    size_t capacity = store._collection->size();
    _collection =
        new HashSetItem(capacity);
    for (size_t i = 0; i < capacity; i++)
    {
        _collection->insertItemLP(store._collection->get(i)->key,
                                 store._collection->get(i)->value);
    }  
}

Store::~Store() {}

string Store::getName()
{
    return _name;
}

void Store::setName(string n)
{
    _name = n;
}

string Store::getAddress()
{
    return _address;
}

void Store::setAddress(string a)
{
    _address = a;
}

int Store::getAnnualRevenue()
{
    return _annual_revenue;
}

void Store::setAnnualRevenue(int r)
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

string Store::sprintItems()
{
    return _collection->sprint();
}

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

string Store::sprintItemsOf()
{
    string result      = "Print by category\n";
    string result_ed   = "\nELECTRONIC DEVICES\n\n";
    string result_food = "\nFOOD\n\n";
    string result_bev  = "\nBEVERAGES\n\n";
    string result_pcp  = "\nPERSONAL CARE PRODUCTS\n\n";

    for (auto node : *_collection)
    //for (size_t i = 0; i < getItemsNumber(); i++)
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

size_t Store::getItemsNumber()
{
    return _collection->size();
}

string Store::sprintCategoryStock()
{
    size_t count_ed   = 0;
    size_t count_food = 0;
    size_t count_bev  = 0;
    size_t count_pcp  = 0;

    for (auto node : *_collection)
    //for (size_t i = 0; i < getItemsNumber(); i++)
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

void Store::addItem(size_t k, Item* item)
{
    _collection->insertItemLP(k, item);
}

Item* Store::removeItem(size_t k)
{
    return _collection->removeItem(k);
}

Item* Store::findItem(size_t k)
{
    return _collection->findItem(k);
}

void Store::updateItem(size_t k,
                       string b,
                       string m,
                       float  new_price,
                       bool   on_discount,
                       int    new_stock)
{
    Item* item = _collection->findItem(k);
    item->brand = b;
    item->model = m;
    item->setPrice(new_price);
    item->setOnDiscount(on_discount);
    item->setStock(new_stock);
    /*_collection->removeItem(k);
    Item* item = new Item(b, m, new_price, on_discount, new_stock);
    _collection->insertItemLP(k, item);*/
}

int Store::totalStock()
{
    int  stocked    = 0;
    size_t* key_values = _collection->keys();

    for (size_t i = 0; i < getItemsNumber(); i++)
    {
        stocked += _collection->findItem(key_values[i])->getStock();
    }

    return stocked;
}
