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

/**
 * @brief Constructor
 * @details Constructor with all fields
 * @param[in] c capacity
 * @param[in] initNode init value for all nodes
 */
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

/**
 * @brief Constructor
 * @details Copy constructor
 * @param[in] hashset reference to HashSet to be copied
 */
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

/**
 * @brief Destructor
 */
template<typename K, typename V> HashSet<K, V>::~HashSet()
{
    delete[] _items;
}

/**
 * @brief Get set size
 * @details Get the number of items in the set
 * @return number of items
 */
template<typename K, typename V> size_t HashSet<K, V>::size() const
{
    return _num_items;
}

/**
 * @brief Check set emptiness
 * @details Check if items number is zero
 * @return true if set is empty, false otherwise
 */
template<typename K, typename V> bool HashSet<K, V>::isEmpty() const
{
    return (_num_items == 0);
}

/**
 * @brief Hash function
 * @details Function defined through % operator. The index of the set to put
 * item with the specified key is calculated with the following formula:
 * $$ index= |k| \mbox{ % } capacity $$
 * @param[in] k reference to key
 * @return calculated index
 */
template<typename K, typename V>
size_t HashSet<K, V>::hashCode(const K& k) const
{
    return k % capacity;
}

/**
 * @brief Linear Probing insertion
 * @details Function performing insertion of a node, with specified key and
 * value, with Linear Probing algorithm.
 * 1) if set is full, function returns;
 * 2) starting index (named \( hashIndex \) is calculated through hash
 * function;
 * 3) if location is available, node is inserted at that index;
 * 4) if location is not available, index is changed linearly with the
 * formula:
 * $$ hashIndex = hashIndex + j, j=0,1,2,... $$
 * until an available location is found.
 * @param[in] k reference to key
 * @param[in] v reference to value
 * @return attempts before inserting item (only for performance testing
 * purpose)
 */
template<typename K, typename V>
size_t HashSet<K, V>::insertItemLP(const K& k, const V& v)
{
    HashNode<K, V>* item      = new HashNode<K, V>(k, v);
    size_t          hashIndex = hashCode(k);
    size_t          counter   = 0;

    if (_num_items >= capacity)
    {
        return -1;
    }
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

/**
 * @brief Quadratic Probing insertion
 * @details Function performing insertion of a node, with specified key and
 * value, with Quadratic Probing algorithm.
 * 1) if set is full, function returns;
 * 2) starting index (named \( hashIndex \) is calculated through hash
 * function;
 * 3) if location is available, node is inserted at that index;
 * 4) if location is not available, index is changed with the formula:
 * $$ hashIndex = hashIndex + j^2, j=0,1,2,... $$
 * until an available location is found.
 * @param[in] k reference to key
 * @param[in] v reference to value
 * @return attempts before inserting item (only for performance testing
 * purpose)
 */
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
        if (++counter > 10 * capacity) // to avoid infinite loop
        {
            return capacity;
        }
    }
    _num_items++;
    _items[hashIndex] = item;
    return counter;
}

/**
 * @brief Item removal
 * @details Item with the specified key is removed, according to Linear
 * Probing algorithm.
 * @param[in] k reference to key
 * @return value of removed item
 */
template<typename K, typename V> V HashSet<K, V>::removeItemLP(const K& k)
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

/**
 * @brief Item removal
 * @details Item with the specified key is removed, according to Quadratic
 * Probing algorithm.
 * @param[in] k reference to key
 * @return value of removed item
 */
template<typename K, typename V> V HashSet<K, V>::removeItemQP(const K& k)
{
    // Apply hash function to find index for given key
    size_t hashIndex = hashCode(k);
    size_t counter   = 0;
    size_t j         = 0;
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
        hashIndex += (j * j);
        j++;
        hashIndex %= capacity;
        if (++counter > capacity) // to avoid infinite loop
        {
            return NULL;
        }
    }

    // If not found return null
    return NULL;
}

/**
 * @brief Item searching
 * @details First item with the specified key is searched, according to Linear
 * Probing algorithm
 * @param[in] k reference to key
 * @return value of searched item
 */
template<typename K, typename V> V HashSet<K, V>::findItemLP(const K& k)
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

/**
 * @brief Item searching
 * @details First item with the specified key is searched, according to
 * Quadratic Probing algorithm
 * @param[in] k reference to key
 * @return value of searched item
 */
template<typename K, typename V> V HashSet<K, V>::findItemQP(const K& k)
{
    // If it is empty not found
    if (isEmpty())
    {
        return NULL;
    }
    // Apply hash function to find index for given key
    size_t hashIndex = hashCode(k);
    size_t counter   = 0;
    size_t j         = 0;
    // finding the node with given key
    while (_items[hashIndex] != nullptr)
    {
        // if node found return its value
        if (_items[hashIndex]->key == k)
        {
            return _items[hashIndex]->value;
        }
        hashIndex += (j * j);
        j++;
        hashIndex %= capacity;
        if (++counter > capacity) // to avoid infinite loop
        {
            return NULL;
        }
    }

    // If not found return null
    return NULL;
}

/**
 * @brief Getting an item
 * @details The item of the set, at the given position, is returned.
 * @param[in] pos position of the item to return
 * @return pointer to returned HashNode
 */
template<typename K, typename V>
HashNode<K, V>* HashSet<K, V>::get(size_t pos) const
{
    return _items[pos];
}

/**
 * @brief Getting all keys
 * @details All keys of the set are returned.
 * @return array of keys of the set
 */
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

/**
 * @brief Getting all values
 * @details All values of the set are returned.
 * @return array of values of the set
 */
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

/**
 * @brief Checking location availability
 * @details The function checks if position specified is available for
 * inserting new items.
 * @param[in] i position of the set to be checked
 * @return true if available, false otherwise
 * @remarks This method is virtual, because in derived classes availability
 * checking depends on the types.
 */
template<typename K, typename V> bool HashSet<K, V>::isAvailable(size_t i)
{
    return _items[i]->isEqual(AVAILABLE);
}

/**
 * @brief Setting location availability
 * @details The function makes position specified available for
 * inserting new items.
 * @param[in] i position of the set to be checked
 * @remarks This method is virtual, because in derived classes availability
 * checking depends on the types.
 */
template<typename K, typename V> void HashSet<K, V>::setAvailable(size_t i)
{
    _items[i]->copy(AVAILABLE);
}

/**
 * @brief Operator[] overloading
 * @details Defining operator [] behaviour
 * @param[in] index position of item to return
 * @return reference to HashNode at given position
 */
template<typename K, typename V>
const HashNode<K, V>& HashSet<K, V>::operator[](size_t index) const
{
    if (index >= capacity)
    {
        return NULL;
    }
    return _items[index];
}

/**
 * @brief Collection starting point
 * @details Defining collection starting point, requested by iterator design
 * pattern
 * @return Iterator of the collection
 */
template<typename K, typename V>
typename HashSet<K, V>::Iterator HashSet<K, V>::begin() const
{
    return HashSet<K, V>::Iterator{ this, 0 };
}

/**
 * @brief Collection ending point
 * @details Defining collection ending point, requested by iterator design
 * pattern
 * @return Iterator of the collection
 */
template<typename K, typename V>
typename HashSet<K, V>::Iterator HashSet<K, V>::end() const
{
    return HashSet<K, V>::Iterator{ this, capacity };
}

/*
 * Iterator methods
 **/

/**
 * @brief Constructor
 * @details Constructor with all fields
 * @param[in] set pointer to HashSet
 * @param[in] index collection index
 */
template<typename K, typename V>
HashSet<K, V>::Iterator::Iterator(const HashSet<K, V>* set, size_t index) :
    _set(set), _index(index)
{}

/**
 * @brief Operator* overloading
 * @details Defining operator * behaviour
 * @return reference to HashNode
 */
template<typename K, typename V>
const HashNode<K, V>& HashSet<K, V>::Iterator::operator*() const
{
    return _set->operator[](_index);
}

/**
 * @brief Operator++ overloading
 * @details Defining operator ++ behaviour (pre-increment)
 * @return reference to Iterator
 */
template<typename K, typename V>
typename HashSet<K, V>::Iterator& HashSet<K, V>::Iterator::operator++()
{
    ++_index;
    return *this;
}

/**
 * @brief Operator!= overloading
 * @details Defining operator != behaviour
 * @param[in] other reference to constant Iterator
 * @return true if this and other are different, false otherwise
 */
template<typename K, typename V>
bool HashSet<K, V>::Iterator::operator!=(
    const HashSet<K, V>::Iterator& other) const
{
    return _index != other._index;
}
