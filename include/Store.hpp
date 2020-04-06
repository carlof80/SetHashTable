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
class Store
{
public:
    explicit Store() = default;
    Store(string n, string a, size_t c);
    Store(Store& store);
    ~Store();

    string getName() const;
    void   setName(string n);
    string getAddress() const;
    void   setAddress(string a);
    size_t getAnnualRevenue() const;
    void   setAnnualRevenue(size_t r);
    string sprintItems();
    string sprintAll(); 
    string sprintItemsOf();
    size_t getItemsNumber() const;
    string sprintCategoryStock();
    void   addItem(size_t k, Item* item);
    Item*  removeItem(size_t k);
    Item*  findItem(size_t k);
    void   updateItem(size_t k,
                      string b,
                      string m,
                      float  new_price,
                      bool   on_discount,
                      size_t new_stock);
    size_t totalStock();

private:
    string       _name;
    string       _address;
    size_t       _annual_revenue;
    HashSetItem* _collection;
};
} // namespace set
