#include<iostream>

template <class K, class D>

class hashmap{
    private:
        struct hashll{ //HASHMAP LINKED LIST
            K key;
            D data;
            struct hashll *next;
        };
        
        uint32_t UID;

        bool keyExists(K key){
            struct hashll *tmp = head;
            while(tmp != NULL){
                if(tmp->key == key){
                    return true;
                }
                tmp = tmp->next;
            }
            
            return false;
        }

        struct hashll *head;

    public:
        hashmap(K key, D data){
            head = new(hashll);
            head->key = key;
            head->data = data;

            UID = *((uint32_t*)&head);
            
        }

        void add(K key,D data){
            if(keyExists(key)){
                std::cout << "[ERROR] The key already exists || MAP UID ["+std::to_string(UID)+"]\n";
                return;
            }

            struct hashll *newElement = new(hashll);
            newElement->key = key;
            newElement->data = data;

            head->next = newElement;
        }

        void remove(K key){
            if(keyExists(key)){
                std::cout << "[ERROR] The key already exists || MAP UID ["+std::to_string(UID)+"]\n";
                return;
            }

            struct hashll tmp1 = head;
            struct hashll tmp2 = head;
            

            while(*tmp1->next->key != key){
                tmp1 = tmp1->next;
            }

            if(tmp1 = head && tmp1->next = NULL){
                printf("error, first element");
                return;
            }

            if(tmp1->next = NULL){
                free(tmp1);
                return;
            }

            tmp2 = tmp1->next->next;
            free(tmp1->next);
            tmp1->next = tmp2;
        }

        D get(K key){
            if(!keyExists(key)) printf("The key does not exists.");

            struct hashll *tmp = head;

            while(tmp->next != NULL){
                if(tmp->key == key){
                    return tmp->data;
                }

                tmp = tmp->next;
            }

            return nullptr;
        }

        uint32_t getUID(){
            return UID;
        }

};

