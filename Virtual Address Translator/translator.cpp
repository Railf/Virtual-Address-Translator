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
#include <queue>            // std::queue
#include <cmath>            // log2, pow

#include "virtual-tlb.h"    // Virtual and TLB bit calculation
#include "tlb-table.h"      // Table of TLB: valid bit, tag, and physical address
#include "page-table.h"     // Table of PageTable physical address and resident bit

//===========================================
//= FUNCTION PROTOTYPES
//===========================================

std::string TLBResult       (const TLB* tlb, const unsigned int index, const unsigned int tag);
std::string PageTableResult (std::string tlbResult, unsigned int virtualPageNumber);
void        UpdateTables    (TLB* tlb, PageTable* pagetable);

//===========================================
//= END = FUNCTION PROTOTYPES
//===========================================



//===========================================
//= FUNCTION MAIN
//===========================================

int main() {
  //=======================================
  //= MEMORY VARIABLES
  //=======================================
  
  int pagesize      = 0;
  int sets          = 0;
  int virtualbits   = 0;
  int physicalbits  = 0;
  
  //=======================================
  //= PRINT HEADER
  //=======================================
  
  std::cout << "==============================================================================================" << '\n';
  std::cout << "= Virtual Address Translator                                                 = Version 0.0.0 =" << '\n';
  std::cout << "==============================================================================================" << '\n';
  
  //=======================================
  //= OBTAIN DATA
  //=======================================
  
  std::cout << std::endl;
  std::cout << "    GATHERING SYSTEM SPECIFICATIONS";
  std::cout << std::endl << std::endl;
  std::cout << "What is the page size for a virtual memory system (KibiB)? "; std::cin >> pagesize;
  std::cout << "How many sets in the direct-mapped instruction TLB?        "; std::cin >> sets;
  std::cout << "How many bits constitute a virtual address?                "; std::cin >> virtualbits;
  std::cout << "How many bits constitute a physical address?               "; std::cin >> physicalbits;
  
  pagesize *= pow(2,10);
  
  //=======================================
  //= CALCULATIONS
  //=======================================
  
  int offset  = log2(pagesize);
  int index   = log2(sets);
  int tag     = virtualbits - index - offset;
  
  int virtualpages  = pow(2, virtualbits - offset);
  int physicalpages = pow(2, physicalbits - offset);
  
  //=======================================
  //= TABLES
  //=======================================
  
  TLB       tlbtable  [index];
  PageTable pagetable [index];
  
  //=======================================
  //= PRINT MEMORY DATA
  //=======================================
  
  std::cout << std::endl;
  std::cout << "    SYSTEM DATA";
  std::cout << std::endl << std::endl;
  std::cout << "Number of Virtual Pages:  " << virtualpages   << '\n';
  std::cout << "Number of Physical Pages: " << physicalpages  << '\n';
  std::cout << "Bits in TLB page offset:  " << offset         << '\n';
  std::cout << "Bits in TLB index:        " << index          << '\n';
  std::cout << "Bits in TLB tag:          " << tag            << '\n';
  
  //=======================================
  //= OBTAIN VIRTUAL ADDRESSES
  //=======================================
  
  unsigned int tempaddress = 0;
  std::queue<unsigned int> addresses;
  
  std::cout << std::endl;
  std::cout << "    TRANSLATION";
  std::cout << std::endl << std::endl;
  std::cout << "Enter virtual address(es), followed by a newline (1 to stop):\n\n";
  
  while (tempaddress != 1)
  {
    std::cin >> std::hex >> tempaddress;
    
    if (tempaddress == 1)
    {
      continue;
    }
    
    addresses.push(tempaddress);
  }
  
  //=======================================
  //= TRANSLATOR OPERATIONS
  //=======================================
  
  std::cout << std::endl;
  std::cout << "Virtual Page #  Page Offset  TLB Tag  TLB Index  TLB Result  PageTable Result  Physical Page #\n";
  std::cout << "--------------  -----------  -------  ---------  ----------  ----------------  ---------------\n";
  
  while (!addresses.empty())
  {
    v.address = addresses.front();
    
    std::cout << std::setw(14) << v.TABLE.page;
    std::cout << std::setw(13) << v.TLB.offset;
    std::cout << std::setw(9)  << v.TLB.tag;
    std::cout << std::setw(11) << v.TLB.index;
    std::cout << std::setw(12) << TLBResult(tlbtable, v.TLB.index, v.TLB.tag);
    std::cout << std::setw(18) << PageTableResult(TLBResult(tlbtable, v.TLB.index, v.TLB.tag), v.TABLE.page);
    std::cout << std::setw(17) << tlbtable[v.TLB.index].phsyicalpage;
    std::cout << std::endl;
      
    UpdateTables(tlbtable, pagetable);
    addresses.pop();
  }
}

//===========================================
//= END = FUNCTION MAIN
//===========================================



//===========================================
//= FUNCTION TLBResult
//===========================================

std::string TLBResult (const TLB* tlb, const unsigned int index, const unsigned int tag)
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

void UpdateTables (TLB* tlb, PageTable* pagetable)
{
  
}

//===========================================
//= END = FUNCTION UpdateTables
//===========================================
