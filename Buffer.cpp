#include <iostream>
#include <iomanip>  
#include <cstring>  
using namespace std;

class Buffer {
private:
    size_t size;
    unsigned char* data;

public:
  
    Buffer() : size(0), data(nullptr) {
        cout << "[Création] Buffer vide (" << size << " octet)" << endl;
    }

  
    Buffer(size_t n) : size(n) {
        data = new unsigned char[size];
        memset(data, 0, size);
        cout << "[Création] Buffer de " << size << " octet(s)" << endl;
    }

   
    Buffer(const Buffer& other) : size(other.size) {
        if (size > 0) {
            data = new unsigned char[size];
            memcpy(data, other.data, size);
        } else {
            data = nullptr;
        }
        cout << "[Copie] Buffer copié (" << size << " octet(s))" << endl;
    }

    
    void fill(unsigned char value) {
        if (data != nullptr) {
            memset(data, value, size);
        }
    }

   
    void printHex() const {
        for (size_t i = 0; i < size; ++i) {
            cout << uppercase << hex << setw(2) << setfill('0') << (int)data[i] << " ";
        }
        cout << endl;
    }

   
    ~Buffer() {
        delete[] data;
        cout << "Destruction du buffer de " << size << " octets" << endl;
    }
};

int main() {
    // Création des buffers
    Buffer buf1;         
    Buffer buf2(8);       
    buf2.fill(0xAA);     
    Buffer buf3 = buf2;   

    
    cout << "Buffer de 0 octet(s)" << endl;
    cout << "Buffer de 8 octet(s) : "; buf2.printHex();
    cout << "Copie : 8 octet(s) : "; buf3.printHex();

    return 0; 
}
