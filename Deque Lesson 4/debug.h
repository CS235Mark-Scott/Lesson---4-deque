#ifndef NDEBUG
using std::cerr;
/****************************************************
 * DISPLAY DEQUE
 * display the contents of a deque for debug purposes
 ****************************************************/
template <class T>
void displayDeque(const deque <T> & rhs)
{
   // display the header info
   cerr << "\ndeque<T>::display()\n";
   cerr << "\tnumCapacity = " << rhs.numCapacity << "\n";

   // display the contents of the array
   cerr << "\tdata = ";
   if (rhs.numCapacity == 0)
      cerr << "NULL";
   else
   {
      cerr << "{ ";
      for (int i = 0; i < rhs.numCapacity; i++)
      {
         if (i != 0)
            cerr << ", ";

         // not wrapped
         //      0   1   2   3   4   5   6
         //    +---+---+---+---+---+---+---+
         //    |   |   | A | B | C |   |   |
         //    +---+---+---+---+---+---+---+
         // iFront = 9     iFrontNormalize() = 2
         // iBack  = 11    iBackNormalize()  = 4
         if (rhs.iFrontNormalize() <= rhs.iBackNormalize() &&  // not wrapped
             rhs.iFrontNormalize() <= i &&
             i <= rhs.iBackNormalize())                        // in range
            cerr << rhs.data[i];

         // wrapped
         //      0   1   2   3   4   5   6
         //    +---+---+---+---+---+---+---+
         //    | B | C |   |   |   |   | A |
         //    +---+---+---+---+---+---+---+
         // iFront = -8    iFrontNormalize() = 6
         // iBack  = -6    iBackNormalize()  = 1
         else if (rhs.iFrontNormalize() > rhs.iBackNormalize() && // wrapped
                  rhs.size() != 0 &&                              // not empty
                  (i <= rhs.iBackNormalize() ||
                   i >= rhs.iFrontNormalize()))                   // in range
            cerr << rhs.data[i];
      }
      cerr << " }";
   }
   cerr << "\n";

   // display the front and back with the normalized values in ()s
   if (rhs.numCapacity)
   {
      cerr << "\tiFront = " << rhs.iFront
           << " ("          << rhs.iFrontNormalize() << ")\n";
      cerr << "\tiBack  = " << rhs.iBack
           << " ("          << rhs.iBackNormalize()  << ")\n";
   }
}
#else
#define displayDeque(d)
#endif // NDEBUG
