#include "canny_edge.h"

using namespace imageio;

Image ApplyCannyEdge (Image input) {
    CompositeFilter composite;

    composite.AddFilter(new CannyEdgeDetect(0.1, 0.3));
    
    Image output;

    composite.Apply( { input }, { &output } );

    return output;
}