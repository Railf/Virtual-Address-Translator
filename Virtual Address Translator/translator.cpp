//
//  translator.cpp
//  Virtual Address Translator
//
//  Created by Railf on 12/5/17.
//  Copyright © 2017 Railf. All rights reserved.
//

#include <iostream>         // std::cout, std::cin
#include <iomanip>          // std::setw
#include <string>           // std::String
#include "virtual-tlb.h"    // Virtual and TLB bit calculation
#include "tlb-table.h"      // Table of TLB: valid bit, tag, and physical address
#include "page-table.h"     // Table of PageTable physical address and resident bit

//===========================================
//= FUNCTION PROTOTYPES
//===========================================

std::string TLBResult (unsigned int index, unsigned int tag);
std::string PageTableResult (std::string tlbResult, unsigned int virtualPageNumber);

//===========================================
//= END = FUNCTION PROTOTYPES
//===========================================



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
    std::cout << std::setw(12) << TLBResult(vir.TLB.index, vir.TLB.tag);
    std::cout << std::setw(18) << PageTableResult(TLBResult(vir.TLB.index, vir.TLB.tag), vir.table.page);
    std::cout << std::setw(17) << tlb.phsyical_page[vir.TLB.index];
    std::cout << std::endl << std::endl;
  }
}

//===========================================
//= END = FUNCTION MAIN
//===========================================



//===========================================
//= FUNCTION TLBResult
//===========================================

std::string TLBResult (unsigned int index, unsigned int tag)
{
  std::string result = "";
  
  return result;
}

//===========================================
//= END = FUNCTION TLBResult
//===========================================



//===========================================
//= FUNCTION PageTableResult
//===========================================

std::string PageTableResult (std::string tlbResult, unsigned int virtualPageNumber)
{
  std::string result = "";
  
  return result;
}

//===========================================
//= END = FUNCTION PageTableResult
//===========================================
