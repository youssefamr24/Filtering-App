//file name : CS112_A3_Part2B_S27-28_20230057_20230502_20231057.cpp
//Authors : Eslam Tamer Abdrabbo | filter 1 & 4 & 7 & 10 & 15
//        : Youssef Amr Mohamed  | filter  2 & 5 & 8 & 11 & 17
//        : Yasmin Mokhtar       | filter  3 & 6 & 9 & 12 & 16
// section: 27,28
//Ids     : 20230057
//        : 20230502
//        : 20231057
//purpose : image processing | Applying filters
// https://drive.google.com/file/d/1Mx5rnPdPx4J5YrZeF-e9fVmu6BNdPdyh/view?usp=sharing => This is the link for System Diagram
//https://github.com/yasminmokhtar/Assinment-3 => This is the link for our Repository in GitHub
#include <iostream>//this is libs
#include <cstdlib>
#include <regex>
#include <string>
#include <random>
#include <ctime>
#include<stdlib.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Image_Class.h"
using namespace std;
bool isvalid(string file)//check validation
{
    regex pattern(".+\\.(jpg|bmp|png|tga)");
    return regex_match(file,pattern);
}
// Filter 1
void Grayscale_Conversion()
{
    string file;
    cout<<"pleas enter photo name with specify extension .jpg, .bmp, .png, .tga : ";
    cin>>file;//take the name
    while (isvalid(file)==false)//check the validation
    {
        cout<<"your photo name not valid, Try again : ";
        cin>>file;
    }
    Image photo(file);//use the class
    for (int i =0;i<photo.width;i++)//convert to gray
    {
        for (int y =0;y<photo.height;y++)
        {
            unsigned  int mean = 0;
            for (int z =0;z<3;z++)
            {
                mean+=photo(i,y,z);
            }
            mean/=3;
            for (int z =0;z<3;z++)
            {


                photo(i,y,z)=mean;
            }
        }
    }
    char choice;
    cout << "Do you want to\n A) Display the image with the same name\n B) make a new name for the image\nchoose a or b : ";
    cin >> choice;
    if (choice == 'A' || choice == 'a'){
        // saving the image and displaying it to the user
        photo.saveImage(file);
        system(file.c_str());

    }
    else if (choice == 'B' || choice == 'b'){
        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga : ";
        cin >> file;
        while (isvalid(file)==false)
        {
            cout<<"your photo name not valid, Try again : ";
            cin>>file;
            isvalid(file);
        }
        photo.saveImage(file);
        system(file.c_str());

    }
    cout<<"your photo is ready";

}
// Filter 2
void black_and_white(Image &image,  string& filename){

    // Convert to grayscale
    for (int i = 0; i < image.width ; ++i) {
        for (int j = 0; j < image.height ; ++j) {
            unsigned int avg = 0; // Initialize average value
            for (int k = 0; k < 3; ++k) {
                avg += image(i,j,k);
            }
            avg = avg/3;
            for (int k = 0; k < 3; ++k) {
                image(i,j,k) = avg; // making the every pixel in gray
            }
        }
    }

    // Convert to black and white
    for (int i = 0; i < image.width ; ++i) {
        for (int j = 0; j < image.height ; ++j) {
            unsigned int bw = 0; // if greater than 128 therefore is closest to white else it is closest to black
            if (image(i,j,0) > 128) { // assuming the image is grayscale, so we only need to check one channel
                bw = 255;
            }
            for (int k = 0; k < 3; ++k) {
                image(i,j,k) = bw;
            }
        }
    }

    char choice;
    cout << "Do you want to\n A) Display the image with the same name\n B) make a new name for the image\n";
    cin >> choice;
    if (choice == 'A' || choice == 'a'){
        // saving the image and displaying it to the user
        image.saveImage(filename);
        system(filename.c_str());

    }
    else if (choice == 'B' || choice == 'b'){
        string new_filename;
        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga : ";
        cin >> new_filename;
        while (isvalid(new_filename)==false)
        {
            cout<<"your photo name not valid, Try again : ";
            cin>>new_filename;
            isvalid(new_filename);
        }
        image.saveImage(new_filename);
        system(new_filename.c_str());

    }

}
// Filter 3
void invertColors() {
    string file;
    cout<<"pleas enter photo name with specify extension .jpg, .bmp, .png, .tga : ";
    cin>>file;//take the name
    while (isvalid(file)==false)//check the validation
    {
        cout<<"your photo name not valid, Try again : ";
        cin>>file;
    }
    Image photo(file);//use the class
    for (int i =0;i<photo.width;i++)//convert to gray
    {
        for (int y =0;y<photo.height;y++)
        {
            for (int z =0;z<3;z++)
            {
                photo(i,y,z)=255-photo(i,y,z);
            }
        }
    }
    char choice;
    cout << "Do you want to\n A) Display the image with the same name\n B) make a new name for the image\nchoose a or b : ";
    cin >> choice;
    if (choice == 'A' || choice == 'a'){
        // saving the image and displaying it to the user
        photo.saveImage(file);
        system(file.c_str());

    }
    else if (choice == 'B' || choice == 'b'){
        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga : ";
        cin >> file;
        while (isvalid(file)==false)
        {
            cout<<"your photo name not valid, Try again : ";
            cin>>file;
            isvalid(file);
        }
        photo.saveImage(file);
        system(file.c_str());

    }
    cout<<"your photo is ready";

// Filter 4
}
void Merge_Images()
{
    string file,file1,file2;//declare
    cout<<"pleas enter photo 1 name with specify extension .jpg, .bmp, .png, .tga : ";
    cin>>file1;//take name 1
    isvalid(file1);
    while (isvalid(file1)==false)//check
    {
        cout<<"your photo name not valid, Try again : ";
        cin>>file1;
        isvalid(file1);
    }
    cout<<"pleas enter photo 2 name with specify extension .jpg, .bmp, .png, .tga : ";
    cin>>file2;//take name 2
    isvalid(file2);
    while (isvalid(file2)==false)//check
    {
        cout<<"your photo name not valid, Try again : ";
        cin>>file2;
        isvalid(file2);
    }
    Image photo1(file1);//use the class
    Image photo2(file2);
    int min_of_w = min(photo1.width,photo2.width);//make the new photo
    int min_of_h = min(photo1.height,photo2.height);
    Image photo3(min_of_w,min_of_h);
    for (int i =0;i<min_of_w;i++)//make the filter
    {
        for (int y =0;y<min_of_h;y++)
        {
            for (int z =0;z<3;z++)
            {
                photo3(i,y,z)=(photo1(i,y,z)+photo2(i,y,z))/2;
                if(photo3(i,y,z)>255)
                {
                    photo3(i,y,z)=255;
                }
            }
        }
    }
    cout<<"enter new name with specify extension .jpg, .bmp, .png, .tga : ";
    cin>>file;//take the new name
    isvalid(file);
    while (isvalid(file)==false)//check
    {
        cout<<"your photo name not valid, Try again : ";
        cin>>file;
        isvalid(file);
    }
    photo3.saveImage(file);
    cout<<"your photo is ready";
    system(file.c_str());//show result


}
//Filter 5
void Flip_image(Image &image,  string& filename){
    char choice;
    cout << "Please choose How do you want the image to be flipped\n";
    cout << "A) Horizonal\nB) Vertical\n";
    cin >> choice;
    if (choice == 'A' || choice == 'a'){
        for (int i = 0; i < image.height; ++i) {
            for (int j = 0; j < image.width / 2; ++j) {
                for (int k = 0; k < 3 ; ++k) {
                    // Swap pixel (i,j,k) with pixel (i, width-j-1, k)
                    unsigned char temp = image.getPixel(j, i, k);
                    image.setPixel(j, i, k, image.getPixel(image.width-j-1, i, k));
                    image.setPixel(image.width-j-1, i, k, temp);
                }
            }
        }
    }
    else if (choice == 'B' || choice == 'b'){
        for (int i = 0; i < image.height / 2; ++i) {
            for (int j = 0; j < image.width; ++j) {
                for (int k = 0; k < 3 ; ++k) {
                    // Swap pixel (i,j,k) with pixel (height-i-1, j, k) as when flipping vertically you need to modify in the height
                    unsigned char temp = image.getPixel(j, i, k);
                    image.setPixel(j, i, k, image.getPixel(j, image.height-i-1, k));
                    image.setPixel(j, image.height-i-1, k, temp);
                }
            }
        }
    }
    else{
        cout << "Wrong input " << endl;
        while(choice !='A' && choice != 'B' && choice != 'a' && choice != 'b' )
        {
            cout<<"Try again : ";
            cin>>choice;
        }
    }
    char choice_2;
    cout << "Do you want to\n A) Display the image with the same name\n B) make a new name for the image\n";
    cin >> choice_2;
    if (choice_2 == 'A' || choice_2 == 'a'){
        // saving the image and displaying it to the user
        image.saveImage(filename);
        system(filename.c_str());

    }
    else if (choice_2 == 'B' || choice_2 == 'b'){
        string new_filename;
        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga : ";
        cin >> new_filename;
        while (isvalid(new_filename)==false)
        {
            cout<<"your photo name not valid, Try again : ";
            cin>>new_filename;
            isvalid(new_filename);
        }
        image.saveImage(new_filename);
        system(new_filename.c_str());

    }


}
//Filter 6
void rotate_image(){


}


// Filter 7
void Darken_and_Lighten_Image()
{
    string file;
    cout<<"pleas enter photo name with specify extension .jpg, .bmp, .png, .tga : ";
    cin>>file;//take the name
    while (isvalid(file)==false)//check
    {
        cout<<"your photo name not valid, Try again : ";
        cin>>file;
    }
    cout<<"Are you want lighten or darken image ?"<<endl;
    cout<<"1) Lighten"<<endl;
    cout<<"2) Darken"<<endl;
    cout<<"choose 1 or 2 : ";//the user choose
    string choice;
    cin>>choice;
    while (choice != "1" && choice != "2")//check
    {
        cout<<"your choice not valid,Try again : ";
        cin>>choice;
    }
    Image photo(file);//use the class
    for (int i =0;i<photo.width;i++)
    {
        for (int y =0;y<photo.height;y++)
        {
            for (int z =0;z<3;z++)
            {
                if(choice == "1")// if user choose lighten
                {
                    photo(i,y,z)= min(255.0,1.5*photo(i,y,z));
                }
                else//if user choose darken
                {
                    photo(i,y,z)-= .5*photo(i,y,z);
                }
            }
        }
    }
    char choice2;
    cout << "Do you want to\n A) Display the image with the same name\n B) make a new name for the image\nchoose a or b : ";
    cin >> choice2;
    if (choice2 == 'A' || choice2 == 'a'){
        // saving the image and displaying it to the user
        photo.saveImage(file);
        system(file.c_str());

    }
    else if (choice2 == 'B' || choice2 == 'b'){
        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga : ";
        cin >> file;
        while (isvalid(file)==false)
        {
            cout<<"your photo name not valid, Try again : ";
            cin>>file;
            isvalid(file);
        }
        photo.saveImage(file);
        system(file.c_str());

    }
    cout<<"your photo is ready";


}
// Filter 8
void crop_image(Image &image, string& image_name){
    // x and y coordinate is the position of the pixel
    int x_coord , y_coord , width , height;
    cout << "Please enter the X-coordinate you want: " << endl;
    cin >> x_coord;
    // checking if the x and y coordinates are valid or not
    while (x_coord < 0 || x_coord >= image.width) {
        cout << "Invalid X-coordinate. Try again: " << endl;
        cin >> x_coord;
    }
    cout << "Please enter the Y-coordinate you want: " << endl;
    cin >> y_coord;
    while (y_coord < 0 || y_coord >= image.height) {
        cout << "Invalid Y-coordinate. Try again: " << endl;
        cin >> y_coord;
    }
    // width and height are the parts that will remain after cropping
    cout << "Please enter the width dimension you want: " << endl;
    cin >> width;
    while (width > image.width - x_coord) {
        cout << "The width you want is greater than the available width. Try again: " <<endl;
        cin >> width;
    }
    cout << "Please enter the height dimension you want: " << endl;
    cin >> height;
    while (height > image.height - y_coord) {
        cout << "The height you want is greater than the available height. Try again: " << endl;
        cin >> height;
    }

    Image cropped_image(width, height); // Create a new image with the desired dimensions

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < 3; k++) {
                // Copy the pixel data from the original image to the new image
                cropped_image.setPixel(i, j, k, image.getPixel(x_coord + i, y_coord + j, k));
            }
        }
    }
    image = cropped_image;
    char choice;
    cout << "Do you want to\n A) Display the image with the same name\n B) make a new name for the image\n";
    cin >> choice;
    if (choice == 'A' || choice == 'a'){
        image.saveImage(image_name);
        system(image_name.c_str());
    }
        //if user wants to make the cropped image in a new name
    else if (choice == 'B' || choice == 'b'){
        string new_filename;
        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga : ";
        cin >> new_filename;
        while (isvalid(new_filename)==false)
        {
            cout<<"your photo name not valid, Try again : ";
            cin>>new_filename;
            isvalid(new_filename); // saving the image
        }
        image.saveImage(new_filename);
        system(new_filename.c_str());
    }
}
// Filter 9
void addBorder() {
    string file;
    cout<<"pleas enter photo name with specify extension .jpg, .bmp, .png, .tga : ";
    cin>>file;//take the name
    while (isvalid(file)==false)//check the validation
    {
        cout<<"your photo name not valid, Try again : ";
        cin>>file;
    }
    Image photo(file);//use the class
    for (int i =0;i<photo.width;i++)//convert to gray
    {
        for (int y =0;y<photo.height;y++)
        {
            if(i<10 || i> photo.width-11 || y<10 || y>photo.height-11)
            {
                photo(i,y,0)=0;
                photo(i,y,1)=0;
                photo(i,y,2)=255;


            }
        }
    }
    char choice;
    cout << "Do you want to\n A) Display the image with the same name\n B) make a new name for the image\nchoose a or b : ";
    cin >> choice;
    if (choice == 'A' || choice == 'a'){
        // saving the image and displaying it to the user
        photo.saveImage(file);
        system(file.c_str());

    }
    else if (choice == 'B' || choice == 'b'){
        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga : ";
        cin >> file;
        while (isvalid(file)==false)
        {
            cout<<"your photo name not valid, Try again : ";
            cin>>file;
            isvalid(file);
        }
        photo.saveImage(file);
        system(file.c_str());

    }
    cout<<"your photo is ready";

}
// Filter 10
void Detect_Image_Edges()
{
    string file;
    cout<<"pleas enter photo name with specify extension .jpg, .bmp, .png, .tga : ";
    cin>>file;//take the name
    while (isvalid(file)==false)//check the validation
    {
        cout<<"your photo name not valid, Try again : ";
        cin>>file;
    }
    Image photo(file);//use the class
    for (int i =0;i<photo.width;i++)//convert to gray
    {
        for (int y =0;y<photo.height;y++)
        {
            unsigned  int mean = 0;
            for (int z =0;z<3;z++)
            {
                mean+=photo(i,y,z);

            }
            mean/=3;


            for (int z =0;z<3;z++)
            {


                photo(i,y,z)=mean;
            }
        }
    }
    //convert to B and W
    for (int i = 0; i < photo.width ; ++i) {
        for (int j = 0; j < photo.height ; ++j) {
            unsigned int bw = 0;
            if (photo(i,j,0) > 128) {
                bw = 255;
            }
            for (int k = 0; k < 3; ++k) {
                photo(i,j,k) = bw;
            }
        }
    }
    //convert to Image Edgis
    unsigned alt =0;
    for (int i =0;i<photo.width;i++)
    {
        for (int y =0;y<photo.height;y++)
        {
            if(i== photo.width-1 || y==photo.height-1 || photo(i,y,0)== 255)
            {
                alt = 0;
                continue;
            }
            if (photo(i,y,0)== 0&& photo(i,y+1,0)==255)
            {
                alt =0;
            }
            if(photo(i,y,0)==0 && alt==1 )
            {
                photo(i,y,0)=255;
                photo(i,y,1)=255;
                photo(i,y,2)=255;
            }
            else if((photo(i,y,0)==0 && alt==0))
            {
                photo(i,y,0)=0;
                photo(i,y,1)=0;
                photo(i,y,2)=0;
                alt=1;
            }
        }
    }
    char choice;
    cout << "Do you want to\n A) Display the image with the same name\n B) make a new name for the image\nchoose a or b : ";
    cin >> choice;
    if (choice == 'A' || choice == 'a'){
        // saving the image and displaying it to the user
        photo.saveImage(file);
        system(file.c_str());

    }
    else if (choice == 'B' || choice == 'b'){
        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga : ";
        cin >> file;
        while (isvalid(file)==false)
        {
            cout<<"your photo name not valid, Try again : ";
            cin>>file;
            isvalid(file);
        }
        photo.saveImage(file);
        system(file.c_str());

    }
    cout<<"your photo is ready";

}

// Filter 11
void resize_image(Image &image,  string& image_name) {
    // get the width and the height and make ration between the old ones with the new ones
    int  new_width, new_height;
    cout << "Please enter the width you want: " << endl;
    cin >> new_width;
    cout << "Please enter the height you want: " << endl;
    cin >> new_height;
    float width_ratio = round((float) image.width / new_width);
    float height_ratio = round((float) image.height / new_height);

    Image new_image(new_width, new_height);

    for (int i = 0; i < new_width; i++) {
        for (int j = 0; j < new_height; j++) {
            // multtiplying the ratio with each pixel content
            int old_i = min((int) (i * width_ratio), image.width - 1);
            int old_j = min((int) (j * height_ratio), image.height - 1);

            for (int k = 0; k < 3; k++) {
                // put the resized image in a new variable called new_image
                new_image(i, j, k) = image(old_i, old_j, k);
            }
        }
    }
    // transfering the content of the resized image to the original cvariable called image
    image = new_image;
    char choice;
    cout << "Do you want to\n A) Display the image with the same name\n B) make a new name for the image\n";
    cin >> choice;
    if (choice == 'A' || choice == 'a'){
        // saving the image and displaying it to the user
        image.saveImage(image_name);
        system(image_name.c_str());

    }
    else if (choice == 'B' || choice == 'b'){
        string new_filename;
        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga : ";
        cin >> new_filename;
        while (isvalid(new_filename)==false)
        {
            cout<<"your photo name not valid, Try again : ";
            cin>>new_filename;
            isvalid(new_filename);
        }
        image.saveImage(new_filename);
        system(new_filename.c_str());

    }


}

//Filter 12
/*void applyBlurFilter(const string& inputImageName, const string& outputImageName) {
    cout << "Applying Blur filter to the image: " << inputImageName << endl;

    // تحميل الصورة
    Image img(inputImageName);

    // الحصول على أبعاد الصورة
    int width = img.width();
    int height = img.height();

    // تطبيق الفلتر Blur
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int totalRed = 0;
            int totalGreen = 0;
            int totalBlue = 0;
            int pixelCount = 0;

            // حساب متوسط قيم اللون للبكسلات المحيطة
            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                        Color pixelColor = img.getPixel(nx, ny);
                        totalRed += pixelColor.red;
                        totalGreen += pixelColor.green;
                        totalBlue += pixelColor.blue;
                        ++pixelCount;
                    }
                }
            }

            // حساب متوسط الألوان
            int avgRed = totalRed / pixelCount;
            int avgGreen = totalGreen / pixelCount;
            int avgBlue = totalBlue / pixelCount;

            // تعيين قيم متوسطة للبكسل الحالي
            img.setPixel(x, y, Color(avgRed, avgGreen, avgBlue));
        }
    }

    // حفظ الصورة بالاسم الجديد
    img.save(outputImageName);
    cout << "Image saved as: " << outputImageName << endl;
}*/
// Filter 15
void televisions()
{
    srand(time(0));
    string file;
    cout<<"pleas enter photo name with specify extension .jpg, .bmp, .png, .tga : ";
    cin.ignore(1,'\n');
    getline(cin,file);//take the name
    while (isvalid(file)==false)//check the validation
    {
        cout<<"your photo name not valid, Try again : ";
        cin>>file;
    }
    Image photo(file);//use the class
    for (int i =0;i<photo.width;i++)//convert to purple
    {
        for (int y =0;y<photo.height;y++)
        {
            for (int z =0;z<3;z++)
            {
                photo(i,y,z) -= .2*photo(i,y,z);
                if(y%2==0)
                {
                    photo(i,y,z)-= 0 + rand()%(40-0+1);

                }
                else
                {
                    photo(i,y,z)= min(255,photo(i,y,z) +(0+ rand()%(30-0+1)));
                }

            }
        }
    }
    char choice;
    cout << "Do you want to\n A) Display the image with the same name\n B) make a new name for the image\nchoose a or b : ";
    cin >> choice;
    if (choice == 'A' || choice == 'a'){
        // saving the image and displaying it to the user
        photo.saveImage(file);
        system(file.c_str());

    }
    else if (choice == 'B' || choice == 'b'){
        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga : ";
        cin >> file;
        while (isvalid(file)==false)
        {
            cout<<"your photo name not valid, Try again : ";
            cin>>file;
            isvalid(file);
        }
        photo.saveImage(file);
        system(file.c_str());

    }
    cout<<"your photo is ready";

}
void applyPurpleFilter() {
    string file;
    cout<<"pleas enter photo name with specify extension .jpg, .bmp, .png, .tga : ";
    cin>>file;//take the name
    while (isvalid(file)==false)//check the validation
    {
        cout<<"your photo name not valid, Try again : ";
        cin>>file;
    }
    Image photo(file);//use the class
    for (int i =0;i<photo.width;i++)//convert to purple
    {
        for (int y =0;y<photo.height;y++)
        {
            for (int z =0;z<3;z++)
            {
                if(z==1)
                {
                    photo(i,y,z)= 0;
                    continue;
                }
                if(z==0)
                {
                    photo(i,y,z)= photo(i,y,z) *.75;
                }
            }
        }
    }
    char choice;
    cout << "Do you want to\n A) Display the image with the same name\n B) make a new name for the image\nchoose a or b : ";
    cin >> choice;
    if (choice == 'A' || choice == 'a'){
        // saving the image and displaying it to the user
        photo.saveImage(file);
        system(file.c_str());

    }
    else if (choice == 'B' || choice == 'b'){
        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga : ";
        cin >> file;
        while (isvalid(file)==false)
        {
            cout<<"your photo name not valid, Try again : ";
            cin>>file;
            isvalid(file);
        }
        photo.saveImage(file);
        system(file.c_str());

    }
    cout<<"your photo is ready";

}

void infrared_filter(Image &image, string& image_name){
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            // Apply grayscale filter
            int gray = 0.299*image(i,j,0) + 0.587*image(i,j,1) + 0.114*image(i,j,2);

            // Maximize the red channel
            image(i,j,0) = 255;

            // Invert green and blue channels
            image(i,j,1) = 255 - gray;
            image(i,j,2) = 255 - gray;
        }
    }



    char choice;
    cout << "Do you want to\n A) Display the image with the same name\n B) make a new name for the image\n";
    cin >> choice;
    if (choice == 'A' || choice == 'a'){
        image.saveImage(image_name);
        system(image_name.c_str());
    }
    else if (choice == 'B' || choice == 'b'){
        string new_filename;
        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga : ";
        cin >> new_filename;
        while (isvalid(new_filename)==false)
        {
            cout<<"your photo name not valid, Try again : ";
            cin>>new_filename;
            isvalid(new_filename);
        }
        image.saveImage(new_filename);
        system(new_filename.c_str());
    }
}

int main() {

    while(true)
    {
        cout<<"                                                | Filters Program |         "<<endl;
        cout<<"which filter are you want ?"<<endl;
        cout<<"1) Grayscale Conversion         [ Filter  1]"<<endl;
        cout<<"2) Black and White              [ Filter  2]"<<endl;
        cout<<"3) Invert Image                 [ Filter  3]"<<endl;
        cout<<"4) Merge Images                 [ Filter  4]"<<endl;
        cout<<"5) Flip Image                   [ Filter  5]"<<endl;
        cout<<"6) Rotate Image                 [ Filter  6]"<<endl;
        cout<<"7) Darken and Lighten Image     [ Filter  7]"<<endl;
        cout<<"8) Crop Images                  [ Filter  8]"<<endl;
        cout<<"9) ِAdding a Frame to the Picture[ Filter  9]"<<endl;
        cout<<"10) Detect Image Edges          [ Filter 10]"<<endl;
        cout<<"11) Resizing Images             [ Filter 11]"<<endl;
        cout<<"12) Blur Images                 [ Filter 12]"<<endl;
        cout<<"13) televisions                 [ Filter 15]"<<endl;
        cout<<"14) purple                      [ Filter 16]"<<endl;
        cout<<"15) infrared filter             [ Filter 17]"<<endl;
        cout<<"16) Exit program "<<endl;
        string choice;
        cout<<"choose number from 1-16 : ";
        cin >> choice;
        if(choice == "1")
        {
            Grayscale_Conversion();
        }
        else if(choice == "2")
        {
            string filename;
            cout << "Please enter the file name: " << endl;
            cin >> filename;
            while (isvalid(filename)==false)
            {
                cout<<"your photo name not valid, Try again : ";
                cin>>filename;
                isvalid(filename);
            }

            Image image(filename);
            if (image.loadNewImage(filename)) { // boolean true or false
                black_and_white(image, filename);
            } else {
                cout << "Wrong input" << endl;
            }

        }
        else if (choice == "3")
        {

            invertColors();

        }
        else if (choice == "4")
        {
            Merge_Images();
        }
        else if (choice == "5")
        {
            string filename;
            cout << "Please enter the file name: " << endl;
            cin >> filename;
            while (isvalid(filename)==false)
            {
                cout<<"your photo name not valid, Try again : ";
                cin>>filename;
                isvalid(filename);
            }
            Image image(filename);
            if (image.loadNewImage(filename)) { // boolean true or false
                Flip_image(image, filename);
            } else {
                cout << "Wrong input" << endl;
            }

        }
        else if (choice == "6")
        {
            rotate_image();

        }
        else if (choice == "7")
        {
            Darken_and_Lighten_Image();
        }
        else if (choice == "8")
        {
            cout << "==== Welcome to Crop image filter ====" << endl;
            string image_name;
            cout << "Please enter the name of the image you want apply cropping on it: ";
            cin >> image_name;
            // validation of the name that the user gives us
            while (!isvalid(image_name))  // Check the return value of isvalid
            {
                cout << "Your photo name isn't valid, try again: ";
                cin >> image_name;
            }
            Image image(image_name);
            if (image.loadNewImage(image_name)) { // boolean true or false
                crop_image(image, image_name);
            } else {
                cout << "Wrong input" << endl;
            }

        }
        else if (choice == "9")
        {
            addBorder();
        }
        else if (choice == "10")
        {
            Detect_Image_Edges();
        }
        else if (choice == "11")
        {
            cout << " ==== Welcome to Resizing image filter ==== " << endl;
            string image_name;
            cout << "Please enter the name of the photo you want to resize it: ";
            cin >> image_name;
            // validation of the name that the user gives us
            while (!isvalid(image_name))  // Check the return value of isvalid
            {
                cout << "Your photo name isn't valid, try again: ";
                cin >> image_name;
            }
            Image image(image_name);
            if (image.loadNewImage(image_name)) { // boolean true or false
                resize_image(image, image_name);
            } else {
                cout << "Wrong input" << endl;
            }

        }
        else if (choice == "12")
        {
            // طلب اسم الصورة من المستخدم
            /* string inputImageName;
             cout << "Enter the name of the input image: ";
             cin >> inputImageName;

             // طلب اسم الصورة المحفوظة باسم جديد
             string outputImageName;
             cout << "Enter the new name to save the image: ";
             cin >> outputImageName;

             // تطبيق فلتر Blur على الصورة وحفظها بالاسم الجديد
             applyBlurFilter(inputImageName, outputImageName);*/

        }
        else if(choice == "13")
        {
            televisions();
        }
        else if (choice == "14")
        {
            applyPurpleFilter();

        }
        else if(choice == "15")
        {
            cout << " ==== Welcome to Infrared image filter ==== " << endl;
            string image_name;
            cout << "Please enter the name of the photo you want to make it in Infrared Photography: ";
            cin >> image_name;
            while (!isvalid(image_name))  // Check the return value of isvalid
            {
                cout << "Your photo name isn't valid, try again: ";
                cin >> image_name;
            }
            Image image(image_name);
            if (image.loadNewImage(image_name)) { // boolean true or false
                infrared_filter(image, image_name);
                image.saveImage(image_name);
            } else {
                cout << "Wrong input" << endl;
            }

        }
        else if (choice == "16")
        {
            break;
        }
        break;
    }
    return 0;
}