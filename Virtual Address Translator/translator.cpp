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

std::string TLBResult       (unsigned int index, unsigned int tag);
std::string PageTableResult (std::string tlbResult, unsigned int virtualPageNumber);
void        UpdateTables    ();

//===========================================
//= END = FUNCTION PROTOTYPES
//===========================================



//===========================================
//= FUNCTION MAIN
//===========================================

int main() {
  unsigned int virtualaddress = 0;
  
  TLB<2>        tlbtable;
  PageTable<2>  pagetable;
  
  while (virtualaddress != 1)
  {
      std::cout << "Virtual address? ";
      std::cin >> std::hex >> virtualaddress;
      
      v.address = virtualaddress;
      
      std::cout << std::endl;
      std::cout << "Virtual Page #  Page Offset  TLB Tag  TLB Index  TLB Result  PageTable Result  Physical Page #";
      std::cout << std::endl;
      std::cout << "--------------  -----------  -------  ---------  ----------  ----------------  ---------------";
      std::cout << std::endl;
      std::cout << std::setw(14) << v.table.page;
      std::cout << std::setw(13) << v.TLB.offset;
      std::cout << std::setw(9)  << v.TLB.tag;
      std::cout << std::setw(11) << v.TLB.index;
      std::cout << std::setw(12) << TLBResult(v.TLB.index, v.TLB.tag);
      std::cout << std::setw(18) << PageTableResult(TLBResult(v.TLB.index, v.TLB.tag), v.table.page);
      std::cout << std::setw(17) << tlbtable.phsyical_page[v.TLB.index];
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


//===========================================
//= FUNCTION UpdateTables
//===========================================

void UpdateTables ()
{
    
}

//===========================================
//= END = FUNCTION UpdateTables
//===========================================
