#include "..\include\PersonalCareProduct.hpp"
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

#include "PersonalCareProduct.hpp"

using namespace set;

PersonalCareProduct::PersonalCareProduct(string                  b,
                                         string                  m,
                                         float                   p,
                                         bool                    d,
                                         int                     s,
                                         PersonalCareProductType t) :
    Item(b, m, p, d, s)
{
    _type = t;
}

PersonalCareProduct::PersonalCareProduct(const PersonalCareProduct& pcp) :
    Item(pcp)
{
    _type = pcp._type;
}

PersonalCareProduct::~PersonalCareProduct() {}

PersonalCareProductType PersonalCareProduct::getType() const
{
    return _type;
}

string PersonalCareProduct::sprint()
{
    const string TYPES[] = { "Shampoo",    "Soap",  "Toothbrush",
                             "Body cream", "Towel", "Comb" };
    string       result  = Item::sprint();
    result += "Type: " + TYPES[(int) _type];
    return result;
}

void PersonalCareProduct::copy(Item& item)
{
    Item::copy(item);
    // PersonalCareProduct* i = dynamic_cast<PersonalCareProduct&>(item);
    // type = i->type;
}
