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

#include "HashNode.hpp"
#include <cstddef>

using namespace set;

/**
 * @brief Constructor
 * @details Constructor with all fields
 * @param[in] k constant reference to key
 * @param[in] v constant reference to value
 */
template<typename K, typename V>
HashNode<K, V>::HashNode(const K& k, const V& v)
{
    key   = k;
    value = v;
}

/**
 * @brief Constructor
 * @details Copy constructor
 * @param[in] h pointer to HashNode to be copied
 */
template<typename K, typename V> HashNode<K, V>::HashNode(HashNode<K, V>* h)
{
    key   = h->key;
    value = h->value;
}

/**
 * @brief Destructor
 */
template<typename K, typename V> HashNode<K, V>::~HashNode() {}

/**
 * @brief Equality check
 * @details Check if this is equal to a specified node
 * @param[in] node pointer to HashNode to be checked
 * @return true if equal, false otherwise
 */
template<typename K, typename V>
bool HashNode<K, V>::isEqual(HashNode<K, V>* node)
{
    return (key == node->key && value == node->value);
}

/**
 * @brief Copy fields
 * @details Copy fields of specified node to this without create it
 * @param[in] node pointer to HashNode to be copied
 */
template<typename K, typename V> void HashNode<K, V>::copy(HashNode<K, V>* node)
{
    key   = node->key;
    value = node->value;
}
