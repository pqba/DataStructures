#pragma once
#include <iostream>
#include <vector>

#include "../../include/Structures/Data.h"
#include "../../include/Structures/Queue.h"

namespace QTest {
void test() {
    Queue<Data> q;
    std::cout << "Queue size: " << q.size() << std::endl;
    std::cout << "Queue is empty: " << std::boolalpha << q.isEmpty() << std::endl;

    // Test 2: Enqueue elements
    std::vector<Data> test_data = {
        Data(1, 1.1, "one"),
        Data(2, 2.2, "two"),
        Data(3, 3.3, "three"),
        Data(4, 4.4, "four"),
        Data(5, 5.5, "five")};

    for (int i = 0; i < (int)test_data.size(); i++) {
        Data data = test_data.at(i);
        q.enqueue(data);
        std::cout << "Enqueued (" << data.print() << "), size: " << q.size() << std::endl;
    }

    // Test 3: Print queue
    std::cout << "Queue contents: " << q.print() << std::endl;

    // Test 4: Dequeue elements
    std::vector<Data> dequeued;
    while (!q.isEmpty()) {
        dequeued.push_back(q.dequeue());
    }

    std::cout << "Dequeued elements: ";
    for (int i = 0; i < (int)dequeued.size(); i++) {
        std::cout << "(" << dequeued.at(i).print() << ") ";
    }
    std::cout << std::endl;

    // Test 5: Enqueue and dequeue elements in a loop
    for (int i = 0; i < 10; i++) {
        Data data(i, static_cast<float>(i) * 0.1, std::to_string(i));
        q.enqueue(data);
        q.dequeue();
        std::cout << "Enqueued (" << data.print() << "), dequeued, size: " << q.size() << std::endl;
    }

    // Test 6: Clear the queue
    q.clear();
    std::cout << "Queue size after clear: " << q.size() << std::endl;
    std::cout << "Queue is empty: " << std::boolalpha << q.isEmpty() << std::endl;

    // Test 7: Initialize queue with an existing array
    Data arr[] = {Data(100, 100.1, "hundred"), Data(200, 200.2, "two hundred"), Data(300, 300.3, "three hundred")};
    Queue<Data> q2(arr, 3);
    std::cout << "Queue from array: " << q2.print() << std::endl;

    // Test 8: Handle exceptions
    try {
        q2.dequeue();
        q2.dequeue();
        q2.dequeue();
        q2.dequeue();  // Should throw an exception
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "Queue tests completed." << std::endl;
}
}  // namespace TestQ