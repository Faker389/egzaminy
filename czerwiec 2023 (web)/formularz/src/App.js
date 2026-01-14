import { useState } from 'react';
import './App.css';
import 'bootstrap/dist/css/bootstrap.css';
import { Button } from 'bootstrap';
function App() {
  const [formData,setFormData]=useState({
    tytul:"",
    kategoria:""
  })
  function displayFormData(){
    console.log(formData)    
  }
 return<main>
  <form>
    <div className="form-group">
      <label>Tytuł filmu</label>
      <input className='form-control' type='text' value={formData.tytul} onChange={(e)=>setFormData({...formData,tytul:e.target.value})} />
      <label>Rodzaj</label>
      <select className='form-control' onChange={(e)=>setFormData({...formData,kategoria:e.target.value})}>
        <option></option>
        <option value={1}>Komeida</option>
        <option value={2}>Obyczajowy</option>
        <option value={3}>Sensacyjny</option>
        <option value={4}>Horror</option>
      </select>
    </div>
    <button type="button" className="btn btn-primary" onClick={displayFormData}>Dodaj</button>
    </form>
 </main>
}

export default App;
