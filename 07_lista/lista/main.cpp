#include <iostream>

using namespace std;

struct  Node{
    int value;
    Node* next;

    Node(int value = 0, Node * next = nullptr){
        this->value = value;
        this->next = next;
    }
};

struct SList{

    Node* head;

    SList(){
        this->head = nullptr;
    }

    ~SList(){
        deletarTudo(head);
    }

    Node * deletarTudo(Node * node){
        if(node == nullptr){
            return nullptr;
        }
        deletarTudo(node->next);
        delete node;
        return nullptr;
    }

    void push_front(int value){
        Node * node = new Node(value);
        node->next = head;
        this->head = node;
    }

    void pop_front(){
        if(head == nullptr)
            return;
        Node * aux = head;
        head = head->next;
        delete aux;
    }

    /*
     * PUSH_BACK INTERATIVO
     */
    void push_back(int value){
        if(head == nullptr){
            head = new Node(value);
            return;
        }
        auto node = head;
        while(node->next != nullptr)
            node = node->next;
        node->next = new Node(value);
    }

    /*
     * PUSH_BACK RECURSIVO
     */
    Node * _rpush_back(Node * node, int value){
        if(node == nullptr)
            return new Node(value);
        node->next = _rpush_back(node->next, value);
        return node;
    }

    void rpush_back(int value){
        head = _rpush_back(head, value);
    }

    /*
     * POP_BACK INTERATIVO
     */
    void pop_back(){
        if(head == nullptr)
            return;
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        auto node = head;
        while(node->next->next != nullptr)
            node = node->next;
        delete node->next;
        node->next = nullptr;
    }

    /*
     * POP_BACK RECURSIVO
     */
    Node * _rpop_back(Node * node){
        if(node->next == nullptr){
            delete node;
            return nullptr;
        }
        node->next = _rpop_back(node->next);
    }

    /*
     * POP_BACK RECURSIVO
     */
    void rpop_back(){
        this->head = _rpop_back(head);
    }

    /*
     * SHOW INTERATIVO
     */
    void ishow(){
        auto node = head;
        while(node != nullptr){
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;
    }

private:
    /*
     * SHOW RECURSIVO PRIVADO
     */
    void _rshow(Node * node){
        if(node == nullptr)
            return;
        _rshow(node->next);
        cout << node->value << " ";
    }

public:
    /*
     * SHOW RECURSIVO PÚBLICO
     */
    void rshow(){
        _rshow(head);
        cout << "" << endl;
    }

    /*
     * REMOVER INTERATIVO
     */
    Node * _iremove(Node * node, int value){
        while(node != nullptr){
            auto aux = node->next;
            if(node->value == value){
                delete node;
                return aux;
            }
            node = aux;
        }
        return nullptr;
    }

    int iremove(int value){
        auto node = head;

                if(node == nullptr)
                    return 0;
                if(node->value == value && node->next == nullptr)
                    pop_back();
                    return 0;
                while(node->next->value == value){
                    auto* aux = node->next->next;
                    node->next = nullptr;
                    delete node->next;
                    head = aux;

                }
                return 0;
    }

    /*
     * REMOVER RECURSIVO
     */
    Node * _rremove(Node * node, int value){
        if(node == nullptr)
            return nullptr;
        if(node->value == value){
            auto aux = node->next;
            delete node;
            return aux;
        }
        node->next = _rremove(node->next, value);
    }

    void rremove(int value){
        head = _rremove(head, value);
    }

    /*
     * Exemplo:
     * 5 9 1 2
     * arrancaRabo(1);
     * 5 9 1
     */
    Node * arrancaRabo(Node * node, int value){
        if(node == nullptr)
            return nullptr;
        if(node->next->value == value){
            return node;
        }
        delete node;
        node->next = arrancaRabo(node->next, value);
    }

    /*
     * Exemplo:
     * 5 9 1 2
     * arrancaVenta(9);
     * 9 1 2
     */
    Node * arrancaVenta(Node * node, int value){
        if(node == nullptr)
            return nullptr;
        node->next = arrancaVenta(node->next, value);
        if(node->next == nullptr){
            if(node->value != value){
                delete node;
                return nullptr;
            }else{
                return node;
            }
        }
        return node;
    }

    void inserir_ordenado(int value){
        auto node = head;
        if(head == nullptr || head->value > value){
            this->head = new Node(value, head);
            return;
        }
        while(node->next != nullptr && node->next->value < value){
            node = node->next;
        }
        node->next = new Node(value, node->next);
    }

    Node * _rinserirOrdenado(Node * node, int value){
           if(node == nullptr || (node->value >= value))
               return new Node(value, node);
           node->next = _rinserirOrdenado(node->next, value);
           return node;
       }

       void rinserirOrdenado(int value){
           head = _rinserirOrdenado(head, value);
   }

    int size(){
        auto node = head;
        int cont = 0;
        while(node != nullptr){
            node = node->next;
            cont++;
        }
        return cont;
    }

    int rsomar(Node * node){
        if(node->next == nullptr)
            return node->value;
        return rsomar(node->next)+node->value;
    }

    int rmin(Node * node){
        if(node->next == nullptr)
            return node->value;
        return std::min(node->value, rmin(node->next));
    }

};

int main(){
    SList lista;
    lista.push_back(5);
    lista.push_back(6);
    lista.push_back(7);
    lista.push_back(10);
    lista.iremove(5);
    lista.rshow();


    return 0;
}
