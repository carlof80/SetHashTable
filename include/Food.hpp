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

#include "FoodType.hpp"
#include "Item.hpp"

namespace set
{
class Food : public Item
{
public:
    /**
     * @brief Default constructor
     */
    explicit Food() = default;

    /**
     * @brief Constructor
     * @details Constructor with all fields
     * @param[in] b Item brand
     * @param[in] m Item model
     * @param[in] p Item price
     * @param[in] d Item onDiscount flag
     * @param[in] s Item stock amount
     * @param[in] t Item type
     * @see Item.hpp
     */
    Food(string b, string m, float p, bool d, int s, FoodType t);

    /**
     * @brief Constructor
     * @details Copy constructor
     * @param[in] food reference to Food to be copied
     * @see Item.hpp
     */
    Food(const Food& food);

    /**
     * @brief Destructor
     */
    ~Food();

    /**
     * @brief Get type of this
     * @details Getter method for field _type
     * @return _type
     */
    FoodType getType() const;

    /**
     * @brief Get production date of this
     * @details Getter method for field _production_date
     * @return _production_date
     */
    string getProductionDate() const;

    /**
     * @brief Set production date of this
     * @details Setter method for field _production_date
     * @param[in] date string of production date
     */
    void setProductionDate(string date);

    /**
     * @brief Get expiration date of this
     * @details Getter method for field _expiration_date
     * @return _expiration_date
     */
    string getExpirationDate() const;

    /**
     * @brief Set expiration date of this
     * @details Setter method for field _expiration_date
     * @param[in] date string of expiration date
     */
    void setExpirationDate(string date);

    /**
     * @brief Print on string Food information
     * @details Information printed are the same of Item ones, plus type
     * @return Result string
     * @remarks Override Item function
     * @see Item.hpp
     */
    string sprint() override;

    /**
     * @brief Item expiration
     * @details Check if item is expired
     * @return true if is expired, false otherwise
     */
    // bool isExpired();

    /**
     * @brief Copy Item
     * @details Item information are copied to this without creating it
     * @param[in] item  pointer to Item to be copied
     * @return void
     * @see Item.hpp
     */
    void copy(Item* item);

private:
    FoodType _type;
    string   _production_date;
    string   _expiration_date;
};
} // namespace set
