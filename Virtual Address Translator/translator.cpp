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

#include "tlb-table.h"      // Table of TLB: valid bit, tag, and physical address
#include "page-table.h"     // Table of PageTable physical address and resident bit

//===========================================
//= FUNCTION PROTOTYPES
//===========================================

std::string TLBResult       (const TLB* tlb, const unsigned int index, const unsigned int tag);
std::string PageTableResult (const std::string tlbResult, const unsigned int virtualpage);
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
  
  std::cout << "=================================================================" << '\n';
  std::cout << "= Virtual Address Translator | Point of Concept | Version 0.0.0 =" << '\n';
  std::cout << "=================================================================" << '\n';
  
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
  
  TLB       tlbtable  [sets];
  PageTable pagetable [sets];
  
  //=======================================
  //= PRINT MEMORY DATA
  //=======================================
  
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "    CALCULATED SYSTEM DATA";
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
  std::cout << std::endl;
  std::cout << "    BEGIN TRANSLATION";
  std::cout << std::endl << std::endl;
  std::cout << "Enter virtual address(es), followed by a newline (0xDEAD to stop):\n\n";
  
  while (tempaddress != 0xDEAD)
  {
    std::cin >> std::hex >> tempaddress;
    
    if (tempaddress == 0xDEAD)
    {
      continue;
    }
    
    addresses.push(tempaddress);
  }
  
  //=======================================
  //= TRANSLATOR OPERATIONS
  //=======================================
  
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "    TRANSLATION TABLE";
  std::cout << std::endl << std::endl;
  std::cout << "Virtual Address  Virtual Page #  Page Offset  TLB Tag  TLB Index  TLB Result  PageTable Result  Physical Page #\n";
  std::cout << "---------------  --------------  -----------  -------  ---------  ----------  ----------------  ---------------\n";
  
  while (!addresses.empty())
  {
    //==================================
    //= DATA CALCULATIONS
    //==================================
    // Dynamic based on gathered data.
    
    unsigned int address      = addresses.front();
    unsigned int virtualpage = 0;
    
    // OFFSET
    // bits = ceil( log2 ( linesize ) )
    
    offset  = address & (pagesize - 1);                                     // bit mask
    address = address >> static_cast<unsigned int>(ceil(log2(pagesize)));   // bit string shift amount
    
    // PHYSICAL PAGE NUMBER
    // bits = ( tag + index ) - offset
    virtualpage = address;
    
    // INDEX
    // bits = ceil( log2 ( sets ) )
    
    index   = address & (sets - 1);                                         // bit mask
    address = address >> static_cast<unsigned int>(ceil(log2(sets)));       // bit string shift amount
    
    // TAG
    // bits = 32 - ( index + offset )
    
    tag = address;
    
    //==================================
    //= RESULT DISPLAY
    //==================================
    
    std::cout << std::setw(15) << std::hex << addresses.front();
    std::cout << std::setw(16) << std::dec << virtualpage;
    std::cout << std::setw(13) << std::dec << offset;
    std::cout << std::setw(9)  << std::dec << tag;
    std::cout << std::setw(11) << std::dec << index;
    std::cout << std::setw(12) << TLBResult(tlbtable, index, tag);
    std::cout << std::setw(18) << PageTableResult(TLBResult(tlbtable, index, tag), virtualpage);
    std::cout << std::setw(17) << std::dec << tlbtable[index].phsyicalpage;
    std::cout << std::endl;
      
    UpdateTables(tlbtable, pagetable);
    addresses.pop();
  }
  
  std::cout << std::endl;
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
  
  //=======================================
  //= MISS
  //=======================================
  
  if (tlb[index].valid == 0)
  {
    result = "miss";
  }
  
  else if ((tlb[index].valid == 1) && (tlb[index].tag != tag))
  {
    result = "miss";
  }
  
  //=======================================
  //= HIT
  //=======================================
  
  else
  {
    result = "hit";
  }
  
  return result;
}

//===========================================
//= END = FUNCTION TLBResult
//===========================================



//===========================================
//= FUNCTION PageTableResult
//===========================================

std::string PageTableResult (const std::string tlbResult, const unsigned int virtualpage)
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
