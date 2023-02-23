// pseudocode for remove method 

void remove(KeyType key) {
    // Calculate the hash value for the given key
    HashType hash_value = hash_function(key);

    // Traverse the list at the hash slot
    for (auto it = table[hash_value].begin(); it != table[hash_value].end(); ++it) {
        // Check if the current element has the given key
        if (it->get_key() == key) {
            // Remove the element from the list
            table[hash_value].erase(it);
            return;
        }
    }

    // If no element with the given key was found, throw an exception
    throw KeyNotFoundException();
}
