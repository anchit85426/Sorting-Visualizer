var div_sizes=[];
var div=[];
var con=document.getElementById("bar");
var no_bars=document.getElementById("arr_size");
var array_size=no_bars.value;
var speed=document.getElementById("speed");

var btn=document.getElementsByClassName("sort");
function create_bars(){
    con.innerHTML="";
    div=[];
    div_sizes=[];
     array_size=no_bars.value;
    for(var i=0;i<array_size;i++){
        
        div_sizes[i]=Math.floor(Math.random() * 100)+1;
        div[i]=document.createElement("DIV");
        var margin_size=0.1;
        div[i].style="margin: 0%"+margin_size+"%;  background-color:blue;  height:"+ div_sizes[i]*5+"px";
        // div[i].innerHTML=div_sizes[i];
        
        div[i].style.width=100/array_size-(2*margin_size)+"%";
        con.appendChild(div[i]);
    }
}
create_bars();
arr_size.addEventListener("input",create_bars);
x.addEventListener("click",create_bars);
speed.addEventListener("input",update_speed);
var_speed=1000;
var delay_time=0;

function update_speed(){
     var_speed=speed.value;
    switch(parseInt(var_speed))
    {
        case 1: var_speed=1;
                break;
        case 2: var_speed=10;
                break;
        case 3: var_speed=100;
                break;
        case 4: var_speed=1000;
                break;
        case 5: var_speed=10000;
                break;
    }
    
    delay_time=10000/(Math.floor(array_size/10)*var_speed);  
    console.log(delay_time);
    console.log(var_speed);
}


 delay_time=10000/Math.floor((array_size/10)*var_speed);
var f=0;
function div_update(cont,height,color){
   
    setTimeout(() => {
        var margin_size=0.1;
        cont.style="margin: 0%"+margin_size+"%;  background-color:"+color+";  height:"+ height*5+"px";
          cont.style.width=100/array_size-(2*margin_size)+"%";
        
        document.getElementById("compare").innerHTML=comparsion+1;
        comparsion+=1;
     },f+=delay_time);
    
}

console.log(btn);
// calling the sorting function if button is pressed;
for(var i=0;i<5;i++){
    btn[i].addEventListener("click",run);
}

function run(){
    console.log(this.innerHTML);
    disable();
    switch(this.innerHTML)
    {
        case "Bubble sort":bubble();
                        break;
        case "Selection sort":selection();
                        break;
        case "Insertion sort":insertion();
                        break;
        case "Merge sort":Merge();
                        break;
        case "Quick sort":Quick();
                        break;
        case "Heap":Heap();
                        break;
    }
    
}

function disable(){
    for(var i=0;i<btn.length;i++){
        btn[i].disabled=true;
    }
    speed.disabled=true;
    no_bars.disabled=true;
    x.disabled=true;
}


function enable_button(){
    setTimeout(() => {
        for(var i=0;i<btn.length;i++){
            btn[i].disabled=false;
        }
        speed.disabled=false;
        comparsion=0;
        no_bars.disabled=false;
        x.disabled=false;
    }, f);
    console.log("x");
    
   
    console.log("x");
}
