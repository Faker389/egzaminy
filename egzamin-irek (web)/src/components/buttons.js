import { Button } from "react-bootstrap";

export  function AllButton({setChecked,checked}){
    return<Button onClick={()=>setChecked("all")} variant={`${checked?"dark":"outline-dark"}`}>Wszystkie</Button>
}
export  function OnWayButton({setChecked,checked}){
    return<Button onClick={()=>setChecked("onWay")}  variant={`${checked?"primary":"outline-primary"}`}>W drodze</Button>
}
export  function DeliveredButton({setChecked,checked}){
    return<Button onClick={()=>setChecked("delivered")}variant={`${checked?"success":"outline-success"}`}>Doręczone</Button>
}