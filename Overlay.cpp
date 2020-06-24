
void Overlay(IplImage* src, IplImage* overlay_img, CvPoint at, CvScalar S, CvScalar D) {

    for(int x=0;xwidth;x++)
    {
        if(x+at.x >= src->width) {
        continue;
        }
        for(int y=0;yheight;y++)
        {
            if(y+at.y&gt;=src-&gt;height){
            continue;
            }

            CvScalar source = cvGet2D(src, y+location.y, x+location.x);
            CvScalar overlay = cvGet2D(overlay_img, y, x);
            CvScalar merged;
            for(int i=0;i&lt;4;i++)
                merged.val[i] = (S.val[i]*source.val[i]+D.val[i]*overlay.val[i])
            cvSet2D(src, y+at.y, x+at.x, merged);
        }
    }
}
