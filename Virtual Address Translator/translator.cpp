//
//  translator.cpp
//  Virtual Address Translator
//
//  Created by Railf on 12/5/17.
//  Copyright © 2017 Railf. All rights reserved.
//

#include <iostream>         // std::cout, std::cin
#include <iomanip>          // std::setw
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
        
        std::cout << std::endl;
        std::cout << "Virtual Page #  Page Offset  TLB Tag  TLB Index  TLB Result  PageTable Result  Physical Page #" << '\n';
        std::cout << "--------------  -----------  -------  ---------  ----------  ----------------  ---------------" << '\n';
        std::cout << std::setw(14) << vir.table.page;
        std::cout << std::setw(13) << vir.TLB.offset;
        std::cout << std::setw(9)  << vir.TLB.tag;
        std::cout << std::setw(11) << vir.TLB.index;
        std::cout << std::endl << std::endl;
    }
}

//===========================================
//= END = FUNCTION MAIN
//===========================================
