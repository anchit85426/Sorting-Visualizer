var con=document.getElementById("bar");
console.log(alert(2));
var no_bars=document.getElementById("arr_size");
function bubble()
{
    for(var i=0;i<array_size-1;i++){
        for(var j=0;j<array_size-i-1;j++){
            // console.log(i,j);
            div_update(div[j],div_sizes[j],"yellow");
            
            if(div_sizes[j]>div_sizes[j+1]){
                div_update(div[j],div_sizes[j],"red");
                div_update(div[j+1],div_sizes[j+1],"red");
                var temp=div_sizes[j];
                div_sizes[j]=div_sizes[j+1];
                div_sizes[j+1]=temp;
             
                div_update(div[j],div_sizes[j],"red");
                div_update(div[j+1],div_sizes[j+1],"red");
                
            }
           div_update(div[j],div_sizes[j],"blue");
        }
        div_update(div[j],div_sizes[j],"green");
    }
    div_update(div[0],div_sizes[0],"green");
    
    enable_button();
    
    
}