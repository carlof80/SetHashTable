#include "..\include\Food.hpp"
/**
 * @copyright Copyright � 2020 SetHashTable. All rights reserved.
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

#include "Food.hpp"
#include <ctime>

using namespace set;

Food::Food(string b, string m, float p, bool d, int s, FoodType t) :
    Item(b, m, p, d, s)
{
    _type            = t;
    _production_date = "N.A."; // Not Available
    _expiration_date = "N.A."; // Not Available
}

Food::Food(const Food& food) : Item(food)
{
    _type            = food._type;
    _production_date = food._production_date;
    _expiration_date = food._expiration_date;
}

Food::~Food() {}

FoodType Food::getType() const
{
    return _type;
}

string Food::getProductionDate() const
{
    return _production_date;
}

void Food::setProductionDate(string date)
{
    _production_date = date;
}

string Food::getExpirationDate() const
{
    return _expiration_date;
}

void Food::setExpirationDate(string date)
{
    _expiration_date = date;
}

bool Food::isExpired()
{
    std::time_t t           = std::time(0); // get time now
    std::tm*    now         = std::localtime(&t);
    size_t      day         = now->tm_mday;
    size_t      month       = now->tm_mon;
    size_t      year        = now->tm_year + 1900;
    size_t      exp_day     = std::stoi(_expiration_date.substr(0, 2));
    string      s_exp_month = _expiration_date.substr(3, 3);
    size_t      exp_month   = 0;
    for (exp_month = 0; exp_month < 12; exp_month++)
    {
        if (s_exp_month == MONTHS[exp_month])
        {
            break;
        }
    }
    size_t exp_year = std::stoi(_expiration_date.substr(7, 4));
    size_t diff_y   = year - exp_year;
    if (diff_y == 0)
    {
        size_t diff_m = month - exp_month;
        if (diff_m == 0)
        {
            size_t diff_d = day - exp_day;
            if (diff_d >= 0)
            {
                return false;
            }
            return true;
        }
        else if (diff_m > 0)
        {
            return false;
        }
        return true;
    }
    else if (diff_y > 0)
    {
        return false;
    }

    return true;
}

string Food::sprint()
{
    const string TYPES[] = { "Meat",  "Fish",   "Vegetables",
                             "Fruit", "Sweets", "Bread" };
    string       result  = Item::sprint();
    result += "Type: " + TYPES[(int) _type] + "\n";
    result += "Production date: " + _production_date + "\n";
    result += "Expiration date: " + _expiration_date + "\n";
    return result;
}

void Food::copy(Item* item)
{
    Item::copy(item);
    _type = dynamic_cast<Food*>(item)->_type;
}
