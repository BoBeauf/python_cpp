#include <iostream>
#include "uECC.h"
#include "uECC_vli.h"
#include "types.h"
using namespace std;

class Key
{
    // Access specifier
    public:
  
    // Data Members
    string PrivateKey;
    string PublicKey;
    
    // Member Functions()
    void initialize(string key)
    {
        PrivateKey = key;
        cout << "Calculating public key with secp256k1 algorithm"<<endl;
        // Calculer la clé publique avec l'algo
        PublicKey = uECC_compute_public_key(0,0,0);
       // PublicKey = "Need to apply function from uECC.h named uECC_compute_public_key";
    }
    string getPrivateKey()
    {
        return PrivateKey;
    }
    string getPublicKey()
    {
        return PublicKey;
    }
};

int main(int argc, const char * argv[]) {
    Key testKey;
    testKey.initialize("4b8e29b9b0dddd58a709edba7d6df6c07ebdaf5653e325114bc5318c238f87f0");
    cout << "Private key is: "<<testKey.getPrivateKey()<<endl;
    cout << "Public key is: "<<testKey.getPublicKey()<<endl;
    return 0;
}