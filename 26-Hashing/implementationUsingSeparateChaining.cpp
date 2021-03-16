#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
class Node{
public:
    string key;
    T value;
    Node<T>* next;

    Node(string key, T val){
        this->key = key;
        value = val;
        next = NULL;
    }
    ~Node(){
        if(next != NULL){
            delete next;
        }
    }
};

template<typename T>
class Hashtable{
    Node<T>** table;    //pointer to an array of pointers
    int current_size;
    int table_size;

    int hashFunc(string key){
        int idx = 0;
        int p = 1;
        for(int i = 0; i < key.length(); i++){
            idx = idx + (key[i] * p)%table_size;
            idx = idx % table_size;
            p = (p * 27) % table_size;
        }
        return idx;
    }

    void rehash(){
        //For Rehash, make a new array of double the previous size and make it the new hash table.
        //Traverse to each element in the old hash table and call insert() for each to insert it into the new larger hash table
        Node<T>** oldTable = table;
        int oldTableSize = table_size;
        table_size = 2 * table_size;
        table = new Node<T>*[table_size];     //table points to a new memory of the type Node*

        for(int i = 0; i < table_size; i++){
            table[i] = NULL;
        }
        current_size = 0;

        for(int i = 0; i < oldTableSize; i++){
            Node<T>* temp = oldTable[i];
            while(temp != NULL){
                insert(temp->key, temp->value);
                temp = temp->next;
            }
            //delete the LL in the old hash table
            if(oldTable[i] != NULL){
                delete oldTable[i];
            }
        }
        //all the LL are deleted,delete the table array
        delete [] oldTable;
    }

public:
    Hashtable(int ts = 7){
        table_size = ts;
        table = new Node<T>*[table_size]; //table is pointing to a memory that is an array of 7 node* buckets
        current_size = 0;                 //Node<T>* is the data-type of each bucket on that array

        for(int i = 0; i < table_size; i++){
            table[i] = NULL;              //a null pointer in a buckets signifies that the bucket does not point to any LL
        }
    }

    void insert(string key, T value){
        //find the index at which the element has to be inserted
        int idx = hashFunc(key);
        //to create a LL,first make a new node
        Node<T>* n = new Node<T>(key, value);
        //insert at the head of the LL of the idx as calculated using hash func
        n->next = table[idx];
        table[idx] = n;
        current_size++;

        //REHASHING
        float load_factor = current_size/(1.0 * table_size);
        //For each addition of a new entry to the map, check the load factor.
        //If its greater than its pre-defined value (or default value of 0.75 if not given), then Rehash.
        if(load_factor > 0.7){
            rehash();
        }
    }

    void print(){
        for(int i = 0; i < table_size; i++){
            cout<<"Bucket "<<i<<" ->";
            //iterate over the LL of this idx
            Node<T>* temp = table[i];
            while(temp != NULL){
                cout<<temp->key<<"("<<temp->value<<") -> ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }

    //we could have returned the value itself instead of the address but in cases where the key i snot present, we will have
    //to return a NULL pointer. Hence the return type of the function is T* because we return the address of the value.
    T* search(string key){
        int idx = hashFunc(key);
        Node<T>* temp = table[idx];

        while(temp != NULL){
            if(temp->key == key){
                return &temp->value;    //return address
            }
            temp = temp->next;
        }
        //if key was not present,return a null ptr and hence the return type of the func will be T*
        return NULL;
    }

    void erase(string key){
        int idx = hashFunc(key);
        Node<T>* temp = table[idx];
        Node<T>* prev = NULL;

        while(temp != NULL){
            if(temp->key == key){
                if(prev){
                    prev->next = temp->next;
                }
                else{
                    table[idx] = temp->next;
                }
                temp->next = NULL;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    //operator [] overloading.
    //return the value of the key by reference because if you don't return it by reference, it will create a copy of the node
    //which will not update the value inside that particular node.
    //The box(node) has a data type T. So to return it by reference,the data type will be T&
    T& operator[](string key){
        //2 possible cases: the key might or might not be present
        T* f = search(key);
        //if key is not present, insert the key value pair with value as some garbage value.
        if(f == NULL){
            //insert key-value pair(value is garbage initially) in the hash map
            T garbage;
            insert(key, garbage);
            //now we can search for the key (key will now be definitely present in the hash map)
            f = search(key);
        }
        //return the value box of the key-value pair to the main. When it is returned to the main, the value is updated.
        return *f;
    }
};

int main(){
    Hashtable<int> price_menu;

    price_menu.insert("Burger", 120);
    price_menu.insert("Pepsi", 20);
    price_menu.insert("Pizza", 150);
    price_menu.insert("Noodles", 25);
    price_menu.insert("Coke", 40);

    price_menu.print();
    cout<<endl;

    int *price = price_menu.search("Noodles");
    if(price == NULL){
        cout<<"Not in the menu!"<<endl;
    }
    else{
        cout<<"Price of Noodles is "<<*price<<endl;   //*price because you're returning the address,hence * will give the value at that address
    }

    price_menu.erase("Coke");
    price_menu.print();
    cout<<endl;

    /*overloading [] operator will support the following operations:
    1. update the key-value pair in the following statement.It will first search for the key "Dosa". If it is present in the hashmap,
       it will update its value to 60 else it will insert this key-value pair in the hashmap*/
    price_menu["Dosa"] = 60;
    price_menu.print();
    cout<<endl;
    //2. update the value of a key
    price_menu["Dosa"] += 10;
    //3. search for a key
    cout<<"Price of Dosa "<<price_menu["Dosa"]<<endl;

    return 0;
}
