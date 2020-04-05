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

#include "Beverage.hpp"
#include "BeverageType.hpp"
#include "ElectronicDevice.hpp"
#include "ElectronicDeviceType.hpp"
#include "PersonalCareProduct.hpp"
#include "PersonalCareProductType.hpp"
#include "Food.hpp"
#include "FoodType.hpp"
#include "HashNode.cpp"
#include "HashNode.hpp"
#include "HashSet.cpp"
#include "HashSet.hpp"
#include "HashSetInt.cpp"
#include "HashSetInt.hpp"
#include "HashSetItem.cpp"
#include "HashSetItem.hpp"
#include "Item.hpp"
#include "Store.cpp"
#include "Store.hpp"
#include <iostream> //std::cout
#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#undef CATCH_CONFIG_MAIN

using namespace set;

TEST_CASE("Set Test", "[SetTest]")
{
    using K               = size_t;
    using V               = size_t;
    const size_t CAPACITY = 5;

    std::cout
        << "---------------------------------------------------------------\n";
    std::cout << "\nTest Hash Set insertion, removing and finding\n";
    std::cout
        << "---------------------------------------------------------------\n";
    HashSetInt* h = new HashSetInt(CAPACITY);
    h->insertItemLP(1, 5);
    h->insertItemLP(2, 7);
    h->insertItemLP(3, 1);

    REQUIRE(h->findItem(2) == 7);

    h->removeItem(2);
    h->insertItemLP(2, 42);

    REQUIRE(h->findItem(2) == 42);

    h->insertItemLP(2, 17);

    REQUIRE(h->findItem(2) == 42);
    
    REQUIRE(h->removeItem(12) == NULL);

    delete h;
}

TEST_CASE("Set Store management", "[StoreTest]")
{
    const size_t    CAPACITY       = 1023;
    const size_t    MAX_KEY_NUMBER = 19999;
    const size_t    MIN_KEY_NUMBER = 10000;
    constexpr float compression_factor =
        (MAX_KEY_NUMBER - MIN_KEY_NUMBER) / CAPACITY;
    std::cout
        << "---------------------------------------------------------------\n";
    std::cout << "\nTest store management\n";
    std::cout
        << "---------------------------------------------------------------\n";
    Store* store =
        new Store("Tosano", "Via Zenate, 1, 37045 Legnago VR", CAPACITY);
    store->addItem(10125,
                   new ElectronicDevice("Samsung",
                                        "S10 Edge+",
                                        949.99f,
                                        false,
                                        10,
                                        ElectronicDeviceType::SMARTPHONE));
    REQUIRE(store->getItemsNumber() == 1);
    store->addItem(
        10584,
        new ElectronicDevice(
            "Acer", "Aspire", 589.99f, false, 23, ElectronicDeviceType::PC));
    store->addItem(
        12973, new Food("AIA", "Chicken", 2.65f, false, 27, FoodType::MEAT));
    store->addItem(11748,
                   new ElectronicDevice("LG",
                                        "F4WV910P2",
                                        729.99f,
                                        true,
                                        7,
                                        ElectronicDeviceType::WASHING_MACHINE));
    store->addItem(
        12441,
        new Beverage(
            "Moretti", "Baffo d'oro", 2.69f, true, 36, BeverageType::BEER));
    store->addItem(
        10849,
        new Food(
            "Mulino Bianco", "Nascondini", 1.59f, false, 12, FoodType::SWEETS));
    INFO("Check items number...")
    REQUIRE(store->getItemsNumber() == 6);
    INFO("Check dynamic cast...")
    REQUIRE(dynamic_cast<ElectronicDevice*>(store->findItem(10584))->type ==
            ElectronicDeviceType::PC);
    INFO("Check stock number...")
    REQUIRE(store->totalStock() == 115);
    std::cout << store->sprintItems() << endl;
    delete store;
}

TEST_CASE("Polymorphism Test", "PolymorphismTest]")
{
    std::cout
        << "---------------------------------------------------------------\n";
    std::cout << "\nPolymorphism Test\n";
    std::cout
        << "---------------------------------------------------------------\n";
    Item* item1 = new ElectronicDevice(
        "Acer", "Aspire", 589.99f, false, 23, ElectronicDeviceType::PC);
    std::cout << item1->sprint() << endl;
    REQUIRE(dynamic_cast<ElectronicDevice*>(item1)->type ==
            ElectronicDeviceType::PC);
    delete item1;
}

TEST_CASE("Iterator Test", "IteratorTest]")
{
    const int CAPACITY = 5;
    std::cout
        << "---------------------------------------------------------------\n";
    std::cout << "\nIterator Test\n";
    std::cout
        << "---------------------------------------------------------------\n";
    Store* store =
        new Store("Tosano", "Via Zenate, 1, 37045 Legnago VR", CAPACITY);
    store->addItem(10125,
                   new ElectronicDevice("Samsung",
                                        "S10 Edge+",
                                        949.99f,
                                        false,
                                        10,
                                        ElectronicDeviceType::SMARTPHONE));
    store->addItem(
        12973, new Food("AIA", "Chicken", 2.65f, false, 27, FoodType::MEAT));
    REQUIRE(store->sprintAll() == store->sprintItems());
    delete store;
}

TEST_CASE("Probing Set Test", "[ProbingSetTest]")
{
    using K               = size_t;
    using V               = size_t;
    const size_t CAPACITY = 11;

    std::cout
        << "---------------------------------------------------------------\n";
    std::cout << "\nLinear vs Quadratic Probing Test\n";
    std::cout
        << "---------------------------------------------------------------\n";
    HashSetInt* h1 = new HashSetInt(CAPACITY);
    h1->insertItemLP(7, 2);
    h1->insertItemLP(2, 4);
    h1->insertItemLP(3, 18);
    h1->insertItemLP(6, 9);
    h1->insertItemLP(4, 41);
    h1->insertItemLP(5, 54);
    h1->insertItemLP(2, 21);
    h1->insertItemLP(2, 98);
    h1->insertItemLP(1, 74);
    size_t attemptsLP = h1->insertItemLP(2, 37);
    std::cout << h1->sprint() << "\n\n";
    delete h1;
    HashSetInt* h2 = new HashSetInt(CAPACITY);
    h2->insertItemQP(7, 2);
    h2->insertItemQP(2, 4);
    h2->insertItemQP(3, 18);
    h2->insertItemQP(6, 9);
    h2->insertItemQP(4, 41);
    h2->insertItemQP(5, 54);
    h2->insertItemQP(2, 21);
    h2->insertItemQP(2, 98);
    h2->insertItemQP(1, 74);
    size_t attemptsQP = h2->insertItemQP(2, 37);
    std::cout << h2->sprint() << "\n\n";
    std::cout << "LP: " << attemptsLP << "\n";
    std::cout << "QP: " << attemptsQP << "\n";
    REQUIRE(attemptsLP < attemptsQP);
    delete h2;
}
