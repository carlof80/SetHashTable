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

#include "HashNode.hpp"
#include <string>

using namespace std;

namespace set
{
template<typename K, typename V> class HashSet
{
public:
    class Iterator
    {
    public:
        Iterator(const HashSet<K, V>* set, size_t nIndex);
        const HashNode<K, V>& operator*() const;
        Iterator&             operator++();
        bool                  operator!=(const Iterator& other) const;

    private:
        const HashSet<K, V>* m_pSet;
        size_t               m_nIndex = -1;
    };

    HashSet(size_t c, HashNode<K, V>* initNode);
    ~HashSet();

    size_t                size();
    bool                  isEmpty();
    size_t                hashCode(const K& k);
    size_t                insertItemLP(const K& k, const V& v);
    size_t                insertItemQP(const K& k, const V& v);
    V                     removeItem(const K& k);
    V                     findItem(const K& k);
    virtual string        sprint() = 0;
    HashNode<K, V>*       get(size_t pos);
    K*                    keys();
    V*                    values();
    virtual bool          isAvailable(size_t i);
    virtual void          setAvailable(size_t i);
    const HashNode<K, V>& operator[](int nIndex) const;
    Iterator              begin() const;
    Iterator              end() const;

protected:
    size_t capacity;

private:
    size_t                 _num_items;
    HashNode<K, V>**       _items;
    static HashNode<K, V>* AVAILABLE;
};

template<typename K, typename V>
HashNode<K, V>* HashSet<K, V>::AVAILABLE = new HashNode<K, V>();

} // namespace set
