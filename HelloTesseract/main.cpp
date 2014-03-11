//
//  main.cpp
//  HelloTesseract
//
//  Created by Haoyu Huang on 3/10/14.
//  Copyright (c) 2014 HaoyuHuang. All rights reserved.
//

#include <iostream>

#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

int main(int argc, const char * argv[])
{

    char *outText;
    
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    // Initialize tesseract-ocr with English, without specifying tessdata path
    if (api->Init(NULL, "eng")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }
    
    // Open input image with leptonica library
    Pix *image = pixRead("RunningTesseract.png");
    api->SetImage(image);
    // Get OCR result
    outText = api->GetUTF8Text();
    printf("OCR output:\n%s", outText);
    
    // Destroy used object and release memory
    api->End();
    delete [] outText;
    pixDestroy(&image);

}

