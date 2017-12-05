//
//  translator.cpp
//  Virtual Address Translator
//
//  Created by Railf on 12/5/17.
//  Copyright © 2017 Railf. All rights reserved.
//

#include <iostream>
#include "virtual-tlb.h"
#include "tlb-table.h"
#include "page-table.h"

int main() {
    unsigned int va = 0;
    
    while (va != 1)
    {
        std::cout << "Virtual address? ";
        std::cin >> std::hex >> va;
        
        vir.x = va;
        
        std::cout << "Vir Page # : " << std::dec << vir.table.page << '\n';
        std::cout << "Page Offset: " << std::hex << vir.TLB.offset << '\n';
        std::cout << "TLB Tag    : " << std::dec << vir.TLB.tag    << '\n';
        std::cout << "TLB Index  : " << std::dec << vir.TLB.index  << '\n' << '\n';
    }
}
