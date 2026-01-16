import { FormCheck } from 'react-bootstrap';
import './App.css';
import 'bootstrap/dist/css/bootstrap.css';
import { useEffect, useState } from 'react';


const dataMockup = [{id: 0, alt: "Mak", filename: "obraz1.jpg", category:1, downloads: 35},
  {id: 1, alt:"Bukiet", filename: "obraz2.jpg", category: 1, downloads: 43},
  {id: 2, alt:"Dalmatyńczyk", filename: "obraz3.jpg", category:2, downloads: 2},
  {id: 3, alt:"Świnka morska", filename: "obraz4.jpg", category:2, downloads: 53},
  {id: 4, alt:"Rotwailer", filename: "obraz5.jpg", category:2, downloads: 43},
  {id: 5, alt:"Audi", filename: "obraz6.jpg", category:3, downloads: 11},
  {id: 6, alt:"kotki", filename: "obraz7.jpg", category:2, downloads: 22},
  {id: 7, alt:"Róża", filename: "obraz8.jpg", category:1, downloads: 33},
  {id: 8, alt:"Świnka morska", filename: "obraz9.jpg", category:2, downloads: 123},
  {id: 9, alt:"Foksterier", filename: "obraz10.jpg", category:2, downloads: 22},
  {id: 10, alt:"Szczeniak", filename: "obraz11.jpg", category:2, downloads: 12},
  {id: 11, alt:"Garbus", filename: "obraz12.jpg", category:3, downloads: 321}]

  export default function App() {
  const [dataM, satDataM] = useState(dataMockup);
  const [checkk, setCheckk] = useState({
    checkBox1:true,
    checkBox2:true,
    checkBox3:true
  })

  function DownloadIncrement(iddx){

    let data = dataM.map(idd=>{
      if(idd.id === iddx){
        return {...idd,downloads:idd.downloads+1}
      }
      return idd;
    })
    satDataM(data)
  }

  const filteredData = dataM.filter(e => {
    const { checkBox1, checkBox2, checkBox3 } = checkk;
    if (e.category === 1 && checkBox1) return true;
    if (e.category === 2 && checkBox2) return true;
    if (e.category === 3 && checkBox3) return true;
    return false;
  });



  return (
    <div className="App">
      
      <h1>Kategorie zdjęć</h1>
      <div class="aa">
     <div class="form-check form-switch">
 <input checked={checkk.checkBox1} class="form-check-input" onChange={(e)=>setCheckk({...checkk, checkBox1:e.target.checked})} type="checkbox" id="ctrId"/>
 <label class="form-check-label" for="ctrId">Kwiaty</label>

</div>
<div class="form-check form-switch">
 <input checked={checkk.checkBox2} class="form-check-input" type="checkbox" onChange={(e)=>setCheckk({...checkk, checkBox2:e.target.checked})} id=" ctrId2"/>
 <label class="form-check-label" for=" ctrId2">Zwierzęta</label>
</div> 

<div class="form-check form-switch">
 <input checked={checkk.checkBox3} class="form-check-input" type="checkbox" onChange={(e)=>setCheckk({...checkk, checkBox3:e.target.checked})} id="ctrId3"/>
 <label class="form-check-label" for="ctrId3">Samochody</label>
</div>
</div>



<div class="kochamciemagrys">
{filteredData.map(idx=>{
  return (
  <div class="jager">
    <img src={`/assets/${idx.filename}`} alt={idx.alt}></img>
    <h4 >Pobrań: {idx.downloads}</h4>
    <button onClick={()=>DownloadIncrement(idx.id)} type="button" class="btn btn-success">Pobierz</button>
  </div>)
})}
</div>
    </div>
  );
  
}
