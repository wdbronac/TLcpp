#include <blkDebug.hpp>
#include <string>



blk::Expr blk::debug(char symb,
		     int width, int height,
		     int ref_width, int ref_height) {
  // This raises a compilation error since Debug constructor is private
  // return std::make_shared<Debug>(symb,width,height,ref_width,ref_height); 
  return blk::Expr(new blk::Debug(symb,
				  width,height,
				  ref_width,ref_height));
}
blk::Debug::Debug(char symb, int width, int height, int ref_width, int ref_height) : Block(width,height,ref_width,ref_height), s(symb){} 

void blk::Debug::printInBoundsLine(std::ostream& os, int i) const { if(i != 0) os << std::string(getWidth(),s);
  else
    for(int j = 0; j < getWidth(); ++j)
      if(j == getRefWidth())
	os << '+';
      else
	os << s;
}


