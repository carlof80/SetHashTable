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

#pragma once

#include "HashSetItem.hpp"
#include "Item.hpp"
#include <string>

using namespace std;

namespace set
{
/**
 *  Class representing a Store
 */
class Store
{
public:
    /**
     * @brief Default constructor
     */
    explicit Store() = default;

    /**
     * @brief Constructor
     * @details Constructor with all fields
     * @param[in] n store name
     * @param[in] a store address
     * @param[in] c store capacity
     */
    Store(string n, string a, size_t c);

    /**
     * @brief Constructor
     * @details Copy constructor
     * @param[in] store reference to Store to be copied
     */
    Store(Store& store);

    /**
     * @brief Destructor
     */
    ~Store();

    /**
     * @brief Gets name of this
     * @details Getter method for field _name
     * @return name
     */
    string getName() const;

    /**
     * @brief Sets name of this
     * @details Setter method for field _name
     * @param[in] n store name
     */
    void setName(string n);

    /**
     * @brief Gets address of this
     * @details Getter method for field _address
     * @return address
     */
    string getAddress() const;

    /**
     * @brief Sets address of this
     * @details Setter method for field _address
     * @param[in] a store address
     */
    void setAddress(string a);

    /**
     * @brief Gets annual revenue of this
     * @details Getter method for field _annual_revenue
     * @return annual revenue
     */
    size_t getAnnualRevenue() const;

    /**
     * @brief Sets annual revenue of this
     * @details Setter method for field _annual_revenue
     * @param[in] r store annual revenue
     */
    void setAnnualRevenue(size_t r);

    /**
     * @brief Prints information on a string
     * @details A string with information of all items of the store is built.
     * @return information string
     * @remarks This method uses standard for loop to print items
     */
    string sprintItems();

    /**
     * @brief Prints information on a string
     * @details A string with information of all items of the store is built.
     * @return information string
     * @remarks This method uses for range loop to print items, for Iterator
     * testing purpose.
     */
    string sprintAll();

    /**
     * @brief Prints information on a string with selection
     * @details A string with information of all items of the store is built.
     * The string is divided by category.
     * @return information string
     * @remarks This method uses for range loop to print items.
     */
    string sprintItemsOf();

    /**
     * @brief Gets size of this
     * @details Total number of items of the store is calculated.
     * @return items number
     */
    size_t getItemsNumber() const;

    /**
     * @brief Prints stock information on a string
     * @details A string with stock number information for all category of
     * product is built.
     * @return information string
     * @remarks This method uses for range loop to print items.
     */
    string sprintCategoryStock();

    /**
     * @brief Adds an item to the store
     * @details A new item with its key is added to the store.
     * @param[in] k key
     * @param[in] item pointer to Item to insert with the given key
     * @remarks This method uses hash table insertion with Linear Probing
     * algorithm.
     */
    void addItem(size_t k, Item* item);

    /**
     * @brief Removes an item from the store
     * @details The item with given key is removed from the store.
     * @param[in] k key
     * @return pointer to removed Item
     * @remarks This method uses hash table removal with Linear Probing
     * algorithm.
     */
    Item* removeItem(size_t k);

    /**
     * @brief Finds an item in the store
     * @details The item with given key is searched in the store.
     * @param[in] k key to search
     * @return pointer to Item found
     * @remarks This method uses hash table removal with Linear Probing
     * algorithm.
     */
    Item* findItem(size_t k);

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
    void updateItem(size_t k,
                    string b,
                    string m,
                    float  new_price,
                    bool   on_discount,
                    size_t new_stock);

    /**
     * @brief Gets stock number of this
     * @details Total number of stocked items of the store is calculated.
     * @return stock number
     */
    size_t totalStock();

private:
    string       _name;           /*!< store name */
    string       _address;        /*!< store address */
    size_t       _annual_revenue; /*!< store annual revenue */
    HashSetItem* _collection;     /*!< store products set */
};
} // namespace set
