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

#include "ElectronicDevice.cpp"
#include "ElectronicDevice.hpp"
#include "ElectronicDeviceType.hpp"
#include "Food.cpp"
#include "Food.hpp"
#include "FoodType.hpp"
#include "HashNode.cpp"
#include "HashNode.hpp"
#include "HashSet.cpp"
#include "HashSet.hpp"
#include "HashSetItem.cpp"
#include "HashSetItem.hpp"
#include "Item.cpp"
#include "Item.hpp"
#include "Store.cpp"
#include "Store.hpp"
#include <iostream>

using namespace std;
using namespace set;

int main()
{
    /*HashSet<int, int>* h = new HashSet<int, int>(10);
    h->insertItemLP(1, 11);
    h->insertItemLP(2, 12);
    h->insertItemLP(2, 13);
    cout << h->sprint() << "\n\n";
    cout << "Size: " << h->size() << endl;
    cout << "Removed: " << h->removeItem(2) << endl;
    cout << h->sprint() << "\n\n";
    cout << "Size: " << h->size() << endl;
    cout << "Is empty: " << h->isEmpty() << endl;
    cout << "Find: " << h->findItem(2) << endl;*/
    // delete h;

    Store store = Store("Tosano", "Via Zenate, 1, 37045 Legnago VR", 1000);
    store.addItem(10125,
                  new ElectronicDevice("Samsung",
                                       "S10 Edge+",
                                       949.99f,
                                       false,
                                       10,
                                       ElectronicDeviceType::SMARTPHONE));
    store.addItem(
        10584,
        new ElectronicDevice(
            "Acer", "Aspire", 589.99f, false, 23, ElectronicDeviceType::PC));
    store.addItem(12973,
                  new Food("AIA", "Chicken", 2.65f, false, 27, FoodType::MEAT));
    store.addItem(11748,
                  new ElectronicDevice("LG",
                                       "F4WV910P2",
                                       729.99f,
                                       true,
                                       7,
                                       ElectronicDeviceType::WASHING_MACHINE));
    store.addItem(
        10849,
        new Food(
            "Mulino Bianco", "Nascondini", 1.59f, false, 12, FoodType::SWEETS));
    cout << store.sprintItems() << endl;

    system("pause");
    return 0;
}
