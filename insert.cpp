// pseudocode for insert method 

template<typename T>
class HashTable {
private:
    // Define a struct for the nodes in the linked list
    struct Node {
        Element<T>* data;   // Pointer to an element
        Node* next;         // Pointer to the next node in the list
        Node* prev;         // Pointer to the previous node in the list
    };
    
    // Define the hash table array and other variables
    Node** table;           // Pointer to an array of Node pointers
    int size;               // Number of slots in the hash table
    int num_elements;       // Number of elements in the hash table
    ...
    
public:
    ...
    
    // Define the insert method
    void insert(T data, int key) {
        // Calculate the hash value for the key
        int hash_value = h(key);
        
        // Create a new Element object with the given data and key
        Element<T>* new_element = new Element<T>(data, key);
        
        // Create a new Node object for the new element
        Node* new_node = new Node;
        new_node->data = new_element;
        new_node->next = nullptr;
        new_node->prev = nullptr;
        
        // Check if the slot at the hash value is empty
        if (table[hash_value] == nullptr) {
            // If the slot is empty, add the new node as the head of the list
            table[hash_value] = new_node;
        } else {
            // If the slot is not empty, add the new node to the head of the list
            // and update the next pointer of the old head node
            new_node->next = table[hash_value];
            table[hash_value]->prev = new_node;
            table[hash_value] = new_node;
        }
        
        // Increment the number of elements in the hash table
        num_elements++;
    }
    
    ...
};
