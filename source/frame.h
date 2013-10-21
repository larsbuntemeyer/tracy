//frame.h

#ifndef _frame_
#define _frame_

#include "vector3d.h"
#include "locator.h"

class frame : public locator {
  public:
    frame();
    frame(vector3d position_in, int width, int height);
    int getWidth() {return m_width;};
    int getHeight() {return m_height;};
    vector3d getPosition() {return m_position;};
    vector3d getLeftUp() {return mLeftUp;};
    void setWidth(int width) {m_width = width;updateFrameCoordinates();};
    void setHeight(int height) {m_height = height;updateFrameCoordinates();};
    void setPosition(vector3d position);
    void translate(float x, float y, float z);
    void rotate(float x, float y, float z);
    vector3d getUnitVecX();
    vector3d getUnitVecY();

  private:
    int m_width,m_height;
    vector3d m_position;
    vector3d mLeftUp,mRightUp,mLeftDown,mRightDown;	//positions of the edges of the frame
    vector3d ex,ey;					//unit vectors of the frame
    void updateFrameCoordinates();
};

#endif
