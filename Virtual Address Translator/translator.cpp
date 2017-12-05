//
//  translator.cpp
//  Virtual Address Translator
//
//  Created by Railf on 12/5/17.
//  Copyright © 2017 Railf. All rights reserved.
//

#include <iostream>         // std::cout, std::cin
#include "virtual-tlb.h"    // Virtual and TLB bit calculation
#include "tlb-table.h"      // Table of TLB: valid bit, tag, and physical address
#include "page-table.h"     // Table of PageTable physical address and resident bit

//===========================================
//= FUNCTION MAIN
//===========================================

int main() {
    unsigned int va = 0;
    
    TLB<2> tlb;
    PageTable<2> pagetable;
    
    while (va != 1)
    {
        std::cout << "Virtual address? ";
        std::cin >> std::hex >> va;
        
        vir.address = va;
        
        std::cout << "Vir Page # : " << std::dec << vir.table.page << '\n';
        std::cout << "Page Offset: " << std::hex << vir.TLB.offset << '\n';
        std::cout << "TLB Tag    : " << std::dec << vir.TLB.tag    << '\n';
        std::cout << "TLB Index  : " << std::dec << vir.TLB.index  << '\n' << '\n';
    }
}

//===========================================
//= END = FUNCTION MAIN
//===========================================
