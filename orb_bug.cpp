#include "opencv2/features2d.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include "test_image.h"

int main()
{
  // Create a 512x512 CV_8UC1 test image
  cv::Mat image;
  createImage( image );

  // Create some keypoints
  std::vector< cv::KeyPoint > keypoints;
  keypoints.push_back( cv::KeyPoint( 146.5, 63.5, 1 ) );
  keypoints.push_back( cv::KeyPoint( 154.5, 63.5, 1 ) );
  keypoints.push_back( cv::KeyPoint( 146.5, 75.5, 1 ) );
  keypoints.push_back( cv::KeyPoint( 154.5, 75.5, 1 ) );

  // Compute the ORB descriptors a significant number of times (eventually crashes)
  for( size_t i=0; i<1000; i++ )
  {
    cv::Mat descriptors;
    cv::Ptr< cv::ORB > orb = cv::ORB::create( 256, 1.2f, 1, 0, 0, 2, cv::ORB::HARRIS_SCORE, 8 );
    orb->compute( image, keypoints, descriptors );
  }

  std::cout << "Finished without errors" << std::endl;
}