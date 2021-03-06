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

using namespace std;

#include "HashSet.hpp"
#include <string>

namespace set
{
/**
 *  Class representing HashSet with key and value of type int
 */
class HashSetInt : public HashSet<size_t, size_t>
{
public:
    /**
     * @brief Default constructor
     */
    explicit HashSetInt() = default;

    /**
     * @brief Constructor
     * @details Constructor with capacity field
     * @param[in] c capacity
     */
    HashSetInt(size_t c);

    /**
     * @brief Constructor
     * @details Copy constructor
     * @param[in] hashSetInt reference to HashSetInt to be copied
     */
    HashSetInt(const HashSetInt& hashSetInt);

    /**
     * @brief Destructor
     */
    ~HashSetInt();

    /**
     * @brief Checking location availability
     * @details The function checks if position specified is available for
     * inserting new items.
     * @param[in] i position of the set to be checked
     * @return true if available, false otherwise
     * @remarks override parent method
     */
    bool isAvailable(size_t i) override;

    /**
     * @brief Setting location availability
     * @details The function makes position specified available for
     * inserting new items.
     * @param[in] i position of the set to be checked
     * @remarks override parent method
     */
    void setAvailable(size_t i) override;

    /**
     * @brief Print information on a string
     * @details A string with information of all items of the set is built.
     * @return information string
     * @remarks override parent method
     */
    string sprint() override;

private:
    static HashNode<size_t, size_t>*
        AVAIL; /*!< Sentinel for node availability (class variable) */
};

HashNode<size_t, size_t>* HashSetInt::AVAIL =
    new HashNode<size_t, size_t>(-1, -1);

} // namespace set
