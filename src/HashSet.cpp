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

#include "HashSet.hpp"
#include <string>

using namespace set;

template<typename K, typename V>
HashSet<K, V>::HashSet(size_t c, HashNode<K, V>* initNode)
{
    capacity   = c;
    _num_items = 0;
    _items     = new HashNode<K, V>*[capacity];
    for (size_t i = 0; i < capacity; i++)
    {
        _items[i] = new HashNode<K, V>(initNode);
    }
}

template<typename K, typename V>
HashSet<K, V>::HashSet(const HashSet<K, V>& hashset)
{
    capacity   = hashset.capacity;
    _num_items = hashset._num_items;
    _items     = new HashNode<K, V>*[capacity];
    for (size_t i = 0; i < capacity; i++)
    {
        _items[i] = new HashNode<K, V>(hashset._items[i]);
    }
}

template<typename K, typename V> HashSet<K, V>::~HashSet()
{
    delete[] _items;
}

template<typename K, typename V> size_t HashSet<K, V>::size() const
{
    return _num_items;
}

template<typename K, typename V> bool HashSet<K, V>::isEmpty() const
{
    return (_num_items == 0);
}

template<typename K, typename V>
size_t HashSet<K, V>::hashCode(const K& k) const
{
    return k % capacity;
}

template<typename K, typename V> bool HashSet<K, V>::isAvailable(size_t i)
{
    return _items[i]->isEqual(AVAILABLE);
}

template<typename K, typename V> void HashSet<K, V>::setAvailable(size_t i)
{
    _items[i]->copy(AVAILABLE);
}

template<typename K, typename V>
size_t HashSet<K, V>::insertItemLP(const K& k, const V& v)
{
    HashNode<K, V>* item      = new HashNode<K, V>(k, v);
    size_t          hashIndex = hashCode(k);
    size_t          counter   = 0;

    while (!isAvailable(hashIndex))
    {
        hashIndex++;
        hashIndex %= capacity;
        if (++counter > capacity) // to avoid infinite loop
        {
            return -1;
        }
    }
    _num_items++;
    _items[hashIndex] = item;
    return counter;
}

template<typename K, typename V>
size_t HashSet<K, V>::insertItemQP(const K& k, const V& v)
{
    HashNode<K, V>* item      = new HashNode<K, V>(k, v);
    size_t          hashIndex = hashCode(k);
    size_t          j         = 0;
    size_t          counter   = 0;

    while (!isAvailable(hashIndex))
    {
        hashIndex += (j * j);
        hashIndex %= capacity;
        j++;
        if (++counter > capacity) // to avoid infinite loop
        {
            return -1;
        }
    }
    _num_items++;
    _items[hashIndex] = item;
    return counter;
}

template<typename K, typename V> V HashSet<K, V>::removeItem(const K& k)
{
    // Apply hash function to find index for given key
    size_t hashIndex = hashCode(k);
    size_t counter   = 0;
    // finding the node with given key
    while (_items[hashIndex] != NULL)
    {
        // if node found
        if (_items[hashIndex]->key == k)
        {
            HashNode<K, V>* cleared = new HashNode<K, V>(_items[hashIndex]);
            // Make removed node available
            setAvailable(hashIndex);
            // Reduce elements number
            _num_items--;
            return cleared->value;
        }
        hashIndex++;
        hashIndex %= capacity;
        if (++counter > capacity) // to avoid infinite loop
        {
            return NULL;
        }
    }

    // If not found return null
    return NULL;
}

template<typename K, typename V> V HashSet<K, V>::findItem(const K& k)
{
    // If it is empty not found
    if (isEmpty())
    {
        return NULL;
    }
    // Apply hash function to find index for given key
    size_t hashIndex = hashCode(k);
    size_t counter   = 0;
    // finding the node with given key
    while (_items[hashIndex] != nullptr)
    {
        // if node found return its value
        if (_items[hashIndex]->key == k)
        {
            return _items[hashIndex]->value;
        }
        hashIndex++;
        hashIndex %= capacity;
        if (++counter > capacity) // to avoid infinite loop
        {
            return NULL;
        }
    }

    // If not found return null
    return NULL;
}

template<typename K, typename V>
HashNode<K, V>* HashSet<K, V>::get(size_t pos) const
{
    return _items[pos];
}

template<typename K, typename V> K* HashSet<K, V>::keys()
{
    K*     retkeys = new K[capacity];
    size_t counter = 0;
    for (size_t i = 0; i < capacity; i++)
    {
        if (!isAvailable(i))
        {
            retkeys[counter++] = _items[i]->key;
        }
    }
    return retkeys;
}

template<typename K, typename V> V* HashSet<K, V>::values()
{
    V*     retvalues = new V[capacity];
    size_t counter   = 0;
    for (size_t i = 0; i < capacity; i++)
    {
        if (!isAvailable(i))
        {
            retvalues[counter++] = _items[i]->value;
        }
    }
    return retvalues;
}

template<typename K, typename V>
typename HashSet<K, V>::Iterator HashSet<K, V>::begin() const
{
    return HashSet<K, V>::Iterator{ this, 0 };
}

template<typename K, typename V>
typename HashSet<K, V>::Iterator HashSet<K, V>::end() const
{
    return HashSet<K, V>::Iterator{ this, capacity };
}

/*
 * Iterator methods
 **/
template<typename K, typename V>
HashSet<K, V>::Iterator::Iterator(const HashSet<K, V>* pVector, size_t nIndex) :
    m_pSet(pVector), m_nIndex(nIndex)
{}

template<typename K, typename V>
const HashNode<K, V>& HashSet<K, V>::operator[](int nIndex) const
{
    if (nIndex >= capacity)
    {
        return NULL;
    }
    return _items[nIndex];
}

template<typename K, typename V>
const HashNode<K, V>& HashSet<K, V>::Iterator::operator*() const
{
    return m_pSet->operator[](m_nIndex);
}

template<typename K, typename V>
typename HashSet<K, V>::Iterator& HashSet<K, V>::Iterator::operator++()
{
    ++m_nIndex;
    return *this;
}

template<typename K, typename V>
bool HashSet<K, V>::Iterator::operator!=(
    const HashSet<K, V>::Iterator& other) const
{
    return m_nIndex != other.m_nIndex;
}
