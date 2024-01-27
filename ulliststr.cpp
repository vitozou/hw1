#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream> // need to remove

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val) {
  // std::cout<<"general test"<<std::endl;

  // std::cout<<size_<<std::endl;
  
  if(head_ == nullptr && tail_ == nullptr) {
    Item* temp = new Item();
    temp->val[0] = val;
    temp->last = 1;
    head_ = temp;
    tail_ = temp;
    size_++;
    // std::cout<<"initialized list"<<std::endl;
    // std::cout<<"the first value of the list is "<<val<<std::endl;
    return;
  }

  // if(size_ == 0) {

  // }

  // std::cout<<"test"<<std::endl;

  int tailSize = tail_->last - tail_->first;
  // bool fullEnd = (tailSize % 10 == 0);
  bool fullEnd = (tail_->last == 10); // should be fine

  // go to the end of the list
  if(fullEnd) { // if there is need for an additional block
    Item* lastBlock = new Item();
    lastBlock->val[0] = val;
    lastBlock->prev = tail_;
    lastBlock->first = 0;
    lastBlock->last = 1;
    tail_->next = lastBlock;
    // delete tail_; // must be unnecessary
    tail_ = lastBlock;
  }
  else { // if can keep using the same list
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  size_++;
  return;
}



void ULListStr::pop_back() {
  if(tail_->last == 0) { // tailSize = 1, need to deallocate tail
    Item* tailPrev = tail_->prev;
    
    delete tail_;
    if(tailPrev != nullptr) {
      tailPrev->next = nullptr;
      tail_ = tailPrev;
    }
    else {
      head_ = nullptr;
      tail_ = nullptr;
    }
    
  }
  else { // tailSize >= 2
    tail_->last--;
  }
  size_--;
}

void ULListStr::push_front(const std::string& val) {
  if(head_ == nullptr && tail_ == nullptr) {
    Item* temp = new Item();
    temp->val[0] = val;
    temp->last = 1;
    head_ = temp;
    tail_ = temp;
    size_++;
    return;
  }

  // int headSize = head_->last - head_->first;
  // bool fullEnd = (head->first % 10 == 0);
  
  bool fullEnd = (head_->first == 0);

  // go to the end of the list
  if(fullEnd) { // if there is need for an additional block
    Item* firstBlock = new Item();
    firstBlock->val[9] = val;
    firstBlock->next = head_;
    firstBlock->first = 9;
    firstBlock->last = 10; // UNIQUE to push_front
    head_->prev = firstBlock;
    // delete head_; // unnecessary?
    head_ = firstBlock;
  }
  else { // if can keep using the same list
    head_->val[head_->first - 1] = val;
    head_->first--;
  }
  size_++;
}

void ULListStr::pop_front() {
  if(head_->first == 9) { // headSize = 1, need to deallocate head
    Item* headsNext = head_->next;
    delete head_;
    if(headsNext != nullptr) {
      headsNext->prev = nullptr;
      head_ = headsNext;
    }
    else {
      head_ = nullptr;
      tail_ = nullptr;
    }
    
  }
  else { // headSize >= 2
    head_->first++;
  }
  size_--;
}

std::string const & ULListStr::back() const {
  return tail_->val[tail_->last - 1]; // this is the last element
}

std::string const & ULListStr::front() const {
  return head_->val[head_->first]; // this is the last element
}

/** 
 * Returns a pointer to the item at index, loc,
 *  if loc is valid and NULL otherwise
 *   - MUST RUN in O(n) 
 */

std::string* ULListStr::getValAtLoc(size_t loc) const {
  // check first to see if loc is within bounds
  if(loc >= size_ || loc < 0) {
    std::cout<<"Out of bounds"<<std::endl;
    return NULL;
  }

  if(loc == 0) {
    std::string* retPointer = &(head_->val[head_->first]);
    return retPointer;
  }
  
  // going to be using an iterator to go through all blocks and counting the elements
  Item* traverser = head_;
  Item* thePrev;
  int sum = 0;
  int currentSize = 0;
  bool found = false;

  while(traverser != nullptr) {
    currentSize = traverser->last - traverser->first;
    if(sum + currentSize > loc) {
      int position = loc - sum + traverser->first;
      std::string* retPointer = &(traverser->val[position]);
      return retPointer;
    }

    sum += currentSize;
    traverser = traverser->next;
  }
  /*
  while(!found) {
    // starts with sum = 0
    currentSize = traverser->last - traverser->first;
    if(sum + currentSize - 1 < loc) { // keep going
      sum += currentSize;
      traverser = traverser->next;
    }
    else if(sum + currentSize - 1 == loc) {
      // std::cout<<"test for loc 1"<<std::endl;
      // std::cout<<"sum = "<<sum<<" and csize = "<<currentSize<<std::endl;
      std::string* retPointer = &(traverser->val[traverser->first + currentSize-1]);
      return retPointer;
    }
    else { // if(sum + currentSize - 1 > loc), we went overboard
      // loc 3, sum = 2 -> loc = 1
      int difference = loc - sum;
      std::string* retPointer = &(traverser->val[difference]);
      return retPointer;
    }
  }
  */

  // if(found) {
  //   std::cout<<"Found it, sum = "<<sum<<" currentSize = "<<currentSize<<std::endl;
  //   std::cout<<"Position is at the block's position "<<loc-sum-1<<std::endl;
  //   std::cout<<"the value = "<<traverser->val[loc-sum-1]<<std::endl;
  // }

  /*
  while(sum != size_) { // loc = 2
    currentSize = traverser->last - traverser->first; // = 4
    // std::cout<<"current size of block = "<<currentSize<<std::endl;
    sum += currentSize; // sum = 4
    if(sum >= loc) {
      // std::cout<<"sum larger than or equal to loc"<<std::endl;
      break;
    }
    if(traverser->next == nullptr) { // THIS WAS THE ISSUE
      // std::cout<<"We are done here."<<std::endl;
      break;
    }
    else {
      // std::cout<<"travelling to next"<<std::endl;
      traverser = traverser->next;
    }
  }
  */
  // std::cout<<std::endl<<" place holder"<<std::endl;
  

  // traverser = traverser->prev; // that'this is wrong, as we assume that there is another block after this
  // std::cout<<"post while loop in getalAtLoc"<<std::endl;
  // std::cout<<traverser->val[0]<<std::endl;
  // now traverser is at the block which contains the element
  // std::cout<<"now again, with val[]="<<traverser->val[traverser->last - (sum - loc)]<<std::endl;

  // std::cout<<"last = "<<traverser->last<<std::endl;
  // std::cout<<"sum = "<<sum<<std::endl;
  // std::cout<<"loc = "<<loc<<std::endl;

  // std::cout<<"post print of traverser->val[0]"<<std::endl;
  // std::string* retPointer = &(traverser->val[traverser->first + currentSize]);
  // std::string* retPointer = &(traverser->val[traverser->last - (sum - loc)]); // this is the issue
  std::string* retPointer = &(traverser->val[loc-sum-1]);
  return retPointer;
}

// MY CODE END

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
