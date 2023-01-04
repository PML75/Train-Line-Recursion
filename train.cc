#include "train.h"

int Train::TotalTrainPassengers()
{
  if (next_carriage_ == nullptr)
  {
    return passenger_count_;
  }
  else
  {
    return passenger_count_ + next_carriage_->TotalTrainPassengers();
  }
}
int Train::MaxCarriagePassengers()
{
  if (next_carriage_ == nullptr)
  {
    return seat_count_;
  }
  else
  {
    int other = next_carriage_->MaxCarriagePassengers();
    if (other > seat_count_)
    {
      return other;
    }
    else
    {
      return seat_count_;
    }
  }
}
bool Train::IsTrainFull()
{
  if (next_carriage_ == nullptr)
  {
    return seat_count_ == passenger_count_;
  }
  else
  {
    return seat_count_ == passenger_count_ && next_carriage_->IsTrainFull();
  }
}
void Train::AddCarriageToEnd(std::shared_ptr<Train> nCarriage)
{
  //This function adds the given Train to the very end of the train
  //Hint: what base case checks if the current Train is the last carriage in the train?
  //Locomotive -> First Class -> Business Class -> Cafe Car -> Carriage 1 -> Carriage 2
  if (next_carriage_ == nullptr)
  {
    next_carriage_ = nCarriage;
  }else{
    next_carriage_->AddCarriageToEnd(nCarriage);
  }
}
