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

using namespace std;

#include <string>

namespace set
{
/**
 *  Class representing an Item, a generic product in a store
 */
class Item
{
public:
    /**
     * @brief Default constructor
     */
    explicit Item() = default;

    /**
     * @brief Constructor
     * @details Constructor with all fields
     * @param[in] b product brand
     * @param[in] m product model
     * @param[in] p product price
     * @param[in] d product on discount flag
     * @param[in] s product stock number
     */
    Item(string b, string m, float p, bool d, size_t s);

    /**
     * @brief Constructor
     * @details Constructor with brand and model fields
     * @param[in] b product brand
     * @param[in] m product model
     */
    Item(string b, string m);

    /**
     * @brief Constructor
     * @details Copy constructor
     * @param[in] other reference to Item to be copied
     */
    Item(const Item& other);

    /**
     * @brief Destructor
     */
    virtual ~Item();

    /**
     * @brief Get price of this
     * @details Getter method for field price
     * @return price
     */
    float getPrice() const;

    /**
     * @brief Set price of this
     * @details Setter method for price field
     * @param[in] p price
     * @return true if no error occurs, false otherwise
     */
    bool setPrice(float p);

    /**
     * @brief Get on discount flag of this
     * @details Getter method for field onDiscount
     * @return true if item is on discount, false otherwise
     */
    bool isOnDiscount() const;

    /**
     * @brief Set on discount flag of this
     * @details Setter method for onDiscount field
     * @param[in] d onDiscount
     */
    void setOnDiscount(bool d);

    /**
     * @brief Get stock number of this
     * @details Getter method for field stock
     * @return stock
     */
    size_t getStock() const;

    /**
     * @brief Set stock number of this
     * @details Setter method for field stock
     * @param[in] s stock number
     */
    void setStock(size_t s);

    /**
     * @brief Print information on a string
     * @details A string with information of all fields of the item is built.
     * @return information string
     * @remarks This is a virtual method, it needs to be implemented by
     * derived class(es), in which there could be other fields to be printed
     */
    virtual string sprint();

    /**
     * @brief Check Item equality
     * @details Check if this and the given item have identical fields values
     * @param[in] item reference to item to check
     * @return true if equality, false otherwise
     */
    bool isEqual(Item& item);

    /**
     * @brief Copy Item
     * @details Item information are copied to this without creating it
     * @param[in] item  reference to Item to be copied
     * @return void
     * @remarks This is a virtual method, it needs to be implemented by
     * derived class(es), in which there could be other fields to be printed
     */
    virtual void copy(Item& item);

    string brand; /*!< Item brand string */
    string model; /*!< Item brand model */

protected:
    float  price;      /*!< Item price */
    bool   onDiscount; /*!< Item on discount flag */
    size_t stock;      /*!< Item stock number */
};

} // namespace set
