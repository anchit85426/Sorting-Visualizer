var con=document.getElementById("bar");
var no_bars=document.getElementById("arr_size");
var n=no_bars.value;
function insertion(){
    for(var j=0;j<array_size;j++)
    {
        div_update(div[j],div_sizes[j],"yellow");//Color update

        var key= div_sizes[j];
        var i=j-1;
        while(i>=0 && div_sizes[i]>key)
        {
            div_update(div[i],div_sizes[i],"red");//Color update
            div_update(div[i+1],div_sizes[i+1],"red");//Color update

            div_sizes[i+1]=div_sizes[i];

            div_update(div[i],div_sizes[i],"red");//Height update
            div_update(div[i+1],div_sizes[i+1],"red");//Height update
    
            div_update(div[i],div_sizes[i],"blue");//Color update
            if(i==(j-1))
            {
                div_update(div[i+1],div_sizes[i+1],"yellow");//Color update
            }
            else
            {
                div_update(div[i+1],div_sizes[i+1],"blue");//Color update
            }
            i-=1;
        }
        div_sizes[i+1]=key;

        for(var t=0;t<j;t++)
        {
            div_update(div[t],div_sizes[t],"green");//Color update
        }
    }
    div_update(div[j-1],div_sizes[j-1],"green");//Color update

    enable_button();
}
