import { useState } from 'react';
import './App.css';
import 'bootstrap/dist/css/bootstrap.css';
const data = ["Programowanie w C#","Angular dla początkujących","Kurs Django"];
function App() {
  const [formData,setFormData]=useState({
    name:"",
    courseNumber:0
  })
  function displayFormData(e){

    const {name,courseNumber}=formData
    console.log(name)
    if(typeof courseNumber==="number"&&(courseNumber>=1&&courseNumber<=3)){
      console.log(data[courseNumber-1])
      return;
    }
    console.log("Nieprawidłowy numer kursu")
  }
  return <main>
      <h2>Liczba kursów: {data.length}</h2>
      <ul>
        {data&&data.map((e,idx)=>{
          return <li key={idx}>{e}</li>
        })}
      </ul>
      <form>
      <div className="form-group">
        <input type="text" className="form-control" value={formData.name} onChange={(e)=>setFormData({...formData,name:e.target.value})} id="name" />
        <label for="name">Imię i nazwisko</label>
        <input type="number" min={0} className="form-control" value={formData.courseNumber} onChange={(e)=>setFormData({...formData,courseNumber:parseInt(e.target.value)})} id="courseNumber" />
        <label for="name">Numer Kursu</label>
      </div>
      <button type='button' className='btn btn-primary' onClick={displayFormData}>Zapisz do kursu</button>
    </form>
  </main>
}

export default App;
