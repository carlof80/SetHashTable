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

#include "Item.hpp"
#include <sstream>

using namespace set;

Item::Item(const Item& other) :
    // initialization-list
    brand(other.brand),
    model(other.model),
    price(other.price),
    onDiscount(other.onDiscount),
    stock(0)
{}

Item::Item(string b, string m, float p, bool d, size_t s) :
    // initialization-list
    brand(b),
    model(m),
    price(p),
    onDiscount(d),
    stock(s)
{}

Item::Item(string b, string m) :
    Item(b, m, 0, false, 0){}; // delegate constructor

Item::~Item() {}

float Item::getPrice() const
{
    return price;
}

bool Item::setPrice(float p)
{
    if (p < 0)
    {
        return false;
    }
    price = p;
    return true;
}

bool Item::isOnDiscount() const
{
    return onDiscount;
}

void Item::setOnDiscount(bool d)
{
    onDiscount = d;
}

size_t Item::getStock() const
{
    return stock;
}

void Item::setStock(int s)
{
    if (s >= 0)
    {
        stock = s;
    }
}

string Item::sprint()
{
    string result = brand + "\n";
    result += model + "\n";
    auto val = [this]() -> string {
        ostringstream out;
        out.precision(2);
        out << fixed << price;
        return out.str();
    };
    result += "Price: " + val() + " EUR\n";
    result += "On discount: " + [this]() -> string {
        if (onDiscount)
        {
            return "YES";
        }
        return "NO";
    }() +
        "\n";
    result += "Stock: " + to_string(stock) + "\n";
    return result;
}

bool Item::isEqual(Item* item)
{
    if (brand == item->brand && model == item->model)
    {
        return true;
    }
    return false;
}

void Item::copy(Item* item)
{
    brand      = item->brand;
    model      = item->model;
    price      = item->price;
    onDiscount = item->onDiscount;
    stock      = item->stock;
}
