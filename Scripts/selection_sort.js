var con=document.getElementById("bar");
var no_bars=document.getElementById("arr_size");
function selection(){
    for(var i=0;i<array_size-1;i++){
        var min_index=i;
        div_update(div[i],div_sizes[i],"red");
        for(var j=i+1;j<array_size;j++){
            
            div_update(div[j],div_sizes[j],"yellow");
            if(div_sizes[j]<div_sizes[min_index]){
                if(min_index!=i){
                    div_update(div[min_index],div_sizes[min_index],"blue");
                }
                min_index=j;
                div_update(div[j],div_sizes[j],"red");
            }
            else{
                div_update(div[j],div_sizes[j],"blue");
            }
        }
        if(min_index!=i){
            var temp=div_sizes[min_index];
            div_sizes[min_index]=div_sizes[i];
            div_sizes[i]=temp;
            div_update(div[min_index],div_sizes[min_index],"red");
            div_update(div[i],div_sizes[i],"red");
            div_update(div[min_index],div_sizes[min_index],"blue");
            
        }
        div_update(div[i],div_sizes[i],"green");
    }
    div_update(div[array_size-1],div_sizes[array_size-1],"green");
}