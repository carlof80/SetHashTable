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

/**
 *  Class representing generic HashSet
 *  Its nodes are generic HashNode
 */
template<typename K, typename V> class HashSet
{
public:
    /**
     *  Inner class representing custom iterator
     */
    class Iterator
    {
    public:
        /**
         * @brief Constructor
         * @details Constructor with all fields
         * @param[in] set pointer to HashSet
         * @param[in] index collection index
         */
        Iterator(const HashSet<K, V>* set, size_t index);

        /**
         * @brief Operator* overloading
         * @details Defining operator * behaviour
         * @return reference to HashNode
         */
        const HashNode<K, V>& operator*() const;

        /**
         * @brief Operator++ overloading
         * @details Defining operator ++ behaviour (pre-increment)
         * @return reference to Iterator
         */
        Iterator& operator++();

        /**
         * @brief Operator!= overloading
         * @details Defining operator != behaviour
         * @param[in] other reference to constant Iterator
         * @return true if this and other are different, false otherwise
         */
        bool operator!=(const Iterator& other) const;

    private:
        const HashSet<K, V>* _set;        /*!< Pointer to HashSet */
        size_t               _index = -1; /*!< Collection index */
    };

    /**
     * @brief Default constructor
     */
    explicit HashSet() = default;

    /**
     * @brief Constructor
     * @details Constructor with all fields
     * @param[in] c capacity
     * @param[in] initNode init value for all nodes
     */
    HashSet(size_t c, HashNode<K, V>* initNode);

    /**
     * @brief Constructor
     * @details Copy constructor
     * @param[in] hashset reference to HashSet to be copied
     */
    HashSet(const HashSet<K, V>& hashset);

    /**
     * @brief Destructor
     */
    virtual ~HashSet();

    /**
     * @brief Get set size
     * @details Get the number of items in the set
     * @return number of items
     */
    size_t size() const;

    /**
     * @brief Check set emptiness
     * @details Check if items number is zero
     * @return true if set is empty, false otherwise
     */
    bool isEmpty() const;

    /**
     * @brief Hash function
     * @details Function defined through % operator. The index of the set to put
     * item with the specified key is calculated with the following formula:
     * $$ index= |k| \mbox{ % } capacity $$
     * @param[in] k reference to key
     * @return calculated index
     */
    size_t hashCode(const K& k) const;

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
    size_t insertItemLP(const K& k, const V& v);

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
    size_t insertItemQP(const K& k, const V& v);

    /**
     * @brief Item removal
     * @details First item with the specified key is removed
     * @param[in] k reference to key
     * @return value of removed item
     */
    V removeItem(const K& k);

    /**
     * @brief Item searching
     * @details First item with the specified key is searched
     * @param[in] k reference to key
     * @return value of searched item
     */
    V findItem(const K& k);

    /**
     * @brief Print information on a string
     * @details A string with information of all items of the set is built.
     * @return information string
     * @remarks This is a pure virtual method, it needs to be implemented by
     * derived class(es), where types are not generic anymore, so a dedicated
     * conversion to string is possible.
     */
    virtual string sprint() = 0;

    /**
     * @brief Getting an item
     * @details The item of the set, at the given position, is returned.
     * @param[in] pos position of the item to return
     * @return pointer to returned HashNode
     */
    HashNode<K, V>* get(size_t pos) const;

    /**
     * @brief Getting all keys
     * @details All keys of the set are returned.
     * @return array of keys of the set
     */
    K* keys();

    /**
     * @brief Getting all values
     * @details All values of the set are returned.
     * @return array of values of the set
     */
    V* values();

    /**
     * @brief Checking location availability
     * @details The function checks if position specified is available for
     * inserting new items.
     * @param[in] i position of the set to be checked
     * @return true if available, false otherwise
     * @remarks This method is virtual, because in derived classes availability
     * checking depends on the types.
     */
    virtual bool isAvailable(size_t i);

    /**
     * @brief Setting location availability
     * @details The function makes position specified available for
     * inserting new items.
     * @param[in] i position of the set to be checked
     * @remarks This method is virtual, because in derived classes availability
     * checking depends on the types.
     */
    virtual void setAvailable(size_t i);

    /**
     * @brief Operator[] overloading
     * @details Defining operator [] behaviour
     * @param[in] index position of item to return
     * @return reference to HashNode at given position
     */
    const HashNode<K, V>& operator[](size_t index) const;

    /**
     * @brief Collection starting point
     * @details Defining collection starting point, requested by iterator design
     * pattern
     * @return Iterator of the collection
     */
    Iterator begin() const;

    /**
     * @brief Collection ending point
     * @details Defining collection ending point, requested by iterator design
     * pattern
     * @return Iterator of the collection
     */
    Iterator end() const;

protected:
    size_t capacity; /*!< Set capacity */

private:
    size_t           _num_items; /*!< Set items number */
    HashNode<K, V>** _items;     /*!< Array of HashNodes */
    static HashNode<K, V>*
        AVAILABLE; /*!< Sentinel for node availability (class variable) */
};

template<typename K, typename V>
HashNode<K, V>* HashSet<K, V>::AVAILABLE = new HashNode<K, V>();

} // namespace set
