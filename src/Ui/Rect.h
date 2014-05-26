#pragma once
namespace Ui {
    enum HorizontalAlignment {
        ALIGN_LEFT, ALIGN_CENTER, ALIGN_RIGHT
    };
    enum VerticalAlignment {
        ALIGN_TOP, ALIGN_MIDDLE, ALIGN_BOTTOM
    };
    
    typedef std::shared_ptr<Rect> RectPtr;
    
    /**
     * Base class for all things Rectangular in the UI.
     */
    class Rect {
        
        public:
            void setParent(RectPtr);
        private:
            RectPtr parent;
            std::list<RectPtr> children;
            
            // x, y, w, h
            float position[4];
            
            // top, right, bottom, left
            float margin[4];
            float padding[4];
            float border[4];
            
            HorizontalAlignment hAlign, parentHAlign;
            VerticalAlignment vAlign, parentVAlign;
            
    };
}