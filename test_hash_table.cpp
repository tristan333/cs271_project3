//
//  test_hashtable.cpp
//  CS 271 Hash Table Project: Test File
//

#include "hash_table.h"
#include <cassert>

void test_constructor() {
    // Test 1: Create hash table with default size
    HashTable<int> ht1;
    assert(ht1.size() == 101);

    // Test 2: Create hash table with size 50
    HashTable<int> ht2(50);
    assert(ht2.size() == 50);

    // Test 3: Create hash table with size 0
    HashTable<int> ht3(0);
    assert(ht3.size() == 101);

    // Test 4: Create hash table with negative size
    HashTable<int> ht4(-10);
    assert(ht4.size() == 101);

    // Test 5: Create hash table with very large size
    HashTable<int> ht5(1000000);
    assert(ht5.size() == 1000000);

    // Add more tests here...

}

int main() {
    test_constructor();
    // Add more test methods here...
    return 0;
}


void test_get_key() {
    try {
        // Test empty element
        Element<int> empty_elem;
        if (empty_elem.get_key() != -1) {
            cout << "ERROR: Test case 1 failed: Expected key=-1, Actual key=" << empty_elem.get_key() << endl;
        }
        
        // Test element with numeric key
        Element<int> numeric_elem(100, 25);
        if (numeric_elem.get_key() != 25) {
            cout << "ERROR: Test case 2 failed: Expected key=25, Actual key=" << numeric_elem.get_key() << endl;
        }
        
        // Test element with string key
        Element<string> string_elem("data", "key");
        if (string_elem.get_key() != "key") {
            cout << "ERROR: Test case 3 failed: Expected key='key', Actual key='" << string_elem.get_key() << "'" << endl;
        }
        
        // Test element with floating-point key
        Element<double> float_elem(3.14, 7.8);
        if (float_elem.get_key() != 7.8) {
            cout << "ERROR: Test case 4 failed: Expected key=7.8, Actual key=" << float_elem.get_key() << endl;
        }
        
        // Test element with negative key
        Element<int> negative_elem(-42, -10);
        if (negative_elem.get_key() != -10) {
            cout << "ERROR: Test case 5 failed: Expected key=-10, Actual key=" << negative_elem.get_key() << endl;
        }
        // Test element with key 0
        Element<int> zero_elem(42, 0);
        if (zero_elem.get_key() != 0) {
            cout << "ERROR: Test case 6 failed: Expected key=0, Actual key=" << zero_elem.get_key() << endl;
        }

        // Test element with key greater than maximum size of hash table
        Element<int> large_elem(42, 1000);
        if (large_elem.get_key() != 1000) {
            cout << "ERROR: Test case 7 failed: Expected key=1000, Actual key=" << large_elem.get_key() << endl;
        }

        // Test element with a very large floating-point key
        Element<double> large_float_elem(3.14, 1e20);
        if (large_float_elem.get_key() != 1e20) {
            cout << "ERROR: Test case 8 failed: Expected key=1e20, Actual key=" << large_float_elem.get_key() << endl;
        }

        // Test element with a key that is a special character
        Element<string> special_char_elem("data", "#");
        if (special_char_elem.get_key() != "#") {
            cout << "ERROR: Test case 9 failed: Expected key='#', Actual key='" << special_char_elem.get_key() << "'" << endl;
        }

        // Test element with a very small floating-point key
        Element<double> small_float_elem(3.14, 1e-20);
        if (small_float_elem.get_key() != 1e-20) {
            cout << "ERROR: Test case 10 failed: Expected key=1e-20, Actual key=" << small_float_elem.get_key() << endl;
        }

            } catch (exception& e) {
                cerr << "Error getting key from element : " << e.what() << endl;
            }
}

void test_get_data() {
    try {
        // Test empty element
        Element<int> empty_elem;
        if (empty_elem.get_data() != 0) {
            cout << "ERROR: Test case 1 failed: Expected data=0, Actual data=" << empty_elem.get_data() << endl;
        }

        // Test element with integer data
        Element<int> int_elem(100, 25);
        if (int_elem.get_data() != 100) {
            cout << "ERROR: Test case 2 failed: Expected data=100, Actual data=" << int_elem.get_data() << endl;
        }

        // Test element with string data
        Element<string> string_elem("string data", "key");
        if (string_elem.get_data() != "string data") {
            cout << "ERROR: Test case 3 failed: Expected data='string data', Actual data='" << string_elem.get_data() << "'" << endl;
        }

        // Test element with floating-point data
        Element<double> float_elem(3.14, 7.8);
        if (float_elem.get_data() != 3.14) {
            cout << "ERROR: Test case 4 failed: Expected data=3.14, Actual data=" << float_elem.get_data() << endl;
        }

        // Test element with negative data
        Element<int> negative_elem(-42, -10);
        if (negative_elem.get_data() != -42) {
            cout << "ERROR: Test case 5 failed: Expected data=-42, Actual data=" << negative_elem.get_data() << endl;
        }
    } catch (exception& e) {
        cerr << "Error getting data from element : " << e.what() << endl;
    }
}


void test_insert() {
    try {
        HashTable<int> empty_ht(0);
        empty_ht.insert(10, 6);
        if(empty_ht.to_string()!="") {
            cout << "Incorrect result of inserting into table. Expected and empty string But got\n\n" << empty_ht.to_string() << endl;
        }
    } catch(exception& e) {
        cout << "Error caused by trying to insert into empty table : " << e.what() << endl;
    }
    try {
        HashTable<int> ht(5);
        ht.insert(10, 6);
        if(ht.to_string()!="0: \n1: (10,6) \n2: \n3: \n4: \n") {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n" << ht.to_string() << endl;
        }
        ht.insert(1, 21);
        if(ht.to_string()!="0: \n1: (1,21) (10,6) \n2: \n3: \n4: \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }
    } catch(exception& e) {
        cerr << "Error inserting into non-empty table : " << e.what() << endl;
    }

        // Test inserting into an empty hash table
    try {
    HashTable<int> empty_ht(0);
    empty_ht.insert(10, 6);
    if(empty_ht.to_string()!="") {
    cout << "Incorrect result of inserting into table. Expected and empty string But got\n\n" << empty_ht.to_string() << endl;
    }
    } catch(exception& e) {
    cout << "Error caused by trying to insert into empty table : " << e.what() << endl;
    }
    // Test inserting into a non-empty hash table
try {
    HashTable<int> ht(5);
    ht.insert(10, 6);
    if(ht.to_string()!="0: \n1: (10,6) \n2: \n3: \n4: \n") {
        cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n" << ht.to_string() << endl;
    }
    ht.insert(1, 21);
    if(ht.to_string()!="0: \n1: (1,21) (10,6) \n2: \n3: \n4: \n") {
        cout << "Incorrect result of inserting into table" << endl;
        }
    } catch(exception& e) {
        cerr << "Error inserting into non-empty table : " << e.what() << endl;
    }

    // Test inserting a duplicate key
    try {
        HashTable<int> ht(5);
        ht.insert(10, 6);
        ht.insert(1, 21);
        ht.insert(10, 5);
        if(ht.to_string()!="0: \n1: (10,5) (1,21) \n2: \n3: \n4: \n") {
            cout << "Incorrect result of inserting a duplicate key into table" << endl;
        }
    } catch(exception& e) {
        cerr << "Error inserting a duplicate key into table : " << e.what() << endl;
    }

    // Test inserting more elements than the hash table size
    try {
        HashTable<int> ht(2);
        ht.insert(10, 6);
        ht.insert(1, 21);
        ht.insert(5, 10);
        if(ht.to_string()!="0: (5,10) \n1: (1,21) \n2: \n3: \n4: \n") {
            cout << "Incorrect result of inserting more elements than the hash table size" << endl;
        }
    } catch(exception& e) {
        cerr << "Error inserting more elements than the hash table size : " << e.what() << endl;
    }

    // Test inserting a large number of elements
    try {
        HashTable<int> ht(100);
        for(int i = 0; i < 100; i++) {
            ht.insert(i, i*2);
        }
        for(int i = 0; i < 100; i++) {
            if(ht.get_data(i) != i*2) {
                cout << "Incorrect result for inserted element " << i << endl;
            }
        }
    } catch(exception& e) {
        cerr << "Error inserting a large number of elements : " << e.what() << endl;
    }

        }