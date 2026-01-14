import { useState } from 'react';
import './App.css';
import 'bootstrap/dist/css/bootstrap.css'
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
function App() {
  const [data,setData]=useState(dataMockup)
  const [checkboxStates,setCheckboxStates]=useState({
    checkbox1:true,
    checkbox2:true,
    checkbox3:true,
  })
  function incrementDownloadCount(imageID){
    const incrementedImagesArray = data.map((e)=>{
      return e.id===imageID?{...e,downloads:e.downloads+1}:{...e}
    })
    setData(incrementedImagesArray)
  }
  const filteredData = data.filter(e => {
    const { checkbox1, checkbox2, checkbox3 } = checkboxStates;
    if (e.category === 1 && checkbox1) return true;
    if (e.category === 2 && checkbox2) return true;
    if (e.category === 3 && checkbox3) return true;
    return false;
  });
  return (
    <div className="App">
      <header>
        <h1>Kategorie zdjęć</h1>
        <section>
        <div class="form-check-inline  form-switch">
          <input class="form-check-input" type="checkbox" onChange={(e)=>setCheckboxStates({...checkboxStates,checkbox1:e.target.checked})} checked={checkboxStates.checkbox1} id="ctrId"/>
          <label class="form-check-label" for="ctrId">Kwiaty</label>
        </div>
        <div class="form-check-inline  form-switch">
          <input class="form-check-input" type="checkbox" onChange={(e)=>setCheckboxStates({...checkboxStates,checkbox2:e.target.checked})} checked={checkboxStates.checkbox2} id=" ctrId2"/>
          <label class="form-check-label" for=" ctrId2">Zwierzęta</label>
        </div>
        <div class="form-check-inline form-switch">
          <input class="form-check-input" type="checkbox" onChange={(e)=>setCheckboxStates({...checkboxStates,checkbox3:e.target.checked})} checked={checkboxStates.checkbox3} id=" ctrId3"/>
          <label class="form-check-label" for=" ctrId3">Samochody</label>
        </div>
        </section>
        <main>
          {filteredData&&filteredData.map((e,idx)=>{
            return <div className='card' key={idx}>
              <img src={`/assets/${e.filename}`} alt={e.alt}  />
              <div>
                <h4>Pobrań: {e.downloads}</h4>
                <button type="button" onClick={()=>incrementDownloadCount(e.id)} class="btn btn-success">Pobierz</button>
              </div>
            </div>
          })}
        </main>
      </header>
    </div>
  );
}

export default App;
