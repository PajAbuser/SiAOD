#include "BinaryFiles.h"
#include "MyHash.h"
#include "HashT.h"

int main() {
    ::srand(::time(nullptr));

    Table table;
    for(int i = 0 ; i < 10 ; i++){
        table.add(Item(rand() % 100));
    }
    table.print();
}