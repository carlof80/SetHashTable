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

#pragma once

namespace set
{
/**
 *  Class representing generic HashNode
 *  Node of a hash table, with key and value
 */
template<typename K, typename V> class HashNode
{
public:
    /**
     * @brief Default constructor
     */
    explicit HashNode() = default;

    /**
     * @brief Constructor
     * @details Constructor with all fields
     * @param[in] k constant reference to key
     * @param[in] v constant reference to value
     */
    HashNode(const K& k, const V& v);

    /**
     * @brief Constructor
     * @details Copy constructor
     * @param[in] h pointer to HashNode to be copied
     */
    HashNode(HashNode<K, V>* h);

    /**
     * @brief Destructor
     */
    ~HashNode();

    /**
     * @brief Equality check
     * @details Check if this is equal to a specified node
     * @param[in] node pointer to HashNode to be checked
     * @return true if equal, false otherwise
     */
    bool isEqual(HashNode<K, V>* node);

    /**
     * @brief Copy fields
     * @details Copy fields of specified node to this without create it
     * @param[in] node pointer to HashNode to be copied
     */
    void copy(HashNode<K, V>* node);

    K key;   /*!< Generic key */
    V value; /*!< Generic value */
};

} // namespace set
