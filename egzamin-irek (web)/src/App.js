import logo from './logo.svg';
import './App.css';
import 'bootstrap/dist/css/bootstrap.css'
import { useEffect, useState } from 'react';
import ShipmentTable from './components/shipmentTable';
import { AllButton, DeliveredButton, OnWayButton } from './components/buttons';
const packagesMockupData = [
  {
    id: "PK-1001",
    trackingNumber: "PL8439201543",
    sender: "TechNova Sp. z o.o.",
    recipient: "Jan Nowak",
    city: "Gdańsk",
    weightKg: 1.2,
    status: "W_DRODZE",
    eta: "2026-01-13",
  },
  {
    id: "PK-1002",
    trackingNumber: "PL8439201888",
    sender: "Sklep Rowerowy KOŁO",
    recipient: "Anna Kowalska",
    city: "Poznań",
    weightKg: 6.8,
    status: "DORĘCZONA",
    eta: "2026-01-10",
  },
  {
    id: "PK-1003",
    trackingNumber: "PL8439201991",
    sender: "BookTown",
    recipient: "Kamil Wiśniewski",
    city: "Warszawa",
    weightKg: 0.7,
    status: "W_DRODZE",
    eta: "2026-01-12",
  },
  {
    id: "PK-1004",
    trackingNumber: "PL8439201777",
    sender: "ElectroMax",
    recipient: "Zuzanna Zielińska",
    city: "Kraków",
    weightKg: 2.4,
    status: "NADANA",
    eta: "2026-01-14",
  },
  {
    id: "PK-1005",
    trackingNumber: "PL8439201666",
    sender: "Dom i Ogród",
    recipient: "Piotr Dąbrowski",
    city: "Wrocław",
    weightKg: 9.1,
    status: "DORĘCZONA",
    eta: "2026-01-09",
  },
  {
    id: "PK-1006",
    trackingNumber: "PL8439201222",
    sender: "FashionPoint",
    recipient: "Oliwia Lewandowska",
    city: "Łódź",
    weightKg: 0.9,
    status: "NADANA",
    eta: "2026-01-15",
  },
  {
    id: "PK-1007",
    trackingNumber: "PL8439201333",
    sender: "AutoParts PRO",
    recipient: "Michał Wójcik",
    city: "Katowice",
    weightKg: 4.5,
    status: "W_DRODZE",
    eta: "2026-01-12",
  },
  {
    id: "PK-1008",
    trackingNumber: "PL8439201444",
    sender: "Komputronixik",
    recipient: "Natalia Szymańska",
    city: "Szczecin",
    weightKg: 3.3,
    status: "DORĘCZONA",
    eta: "2026-01-08",
  },
];
function App() {
  const [filters,setFilters] = useState({
    all:true,
    onWay:false,
    delivered:false
  })
  const filteredData  = packagesMockupData.filter(e=>{
    const {onWay,delivered,all} = filters
      if(e.status==="W_DRODZE"&&onWay) return true
      if(e.status==="DORĘCZONA"&&delivered) return true
      if(all) return true
      return false
  })

  function checkFilter(name){
     const filtersFalse = Object.keys(filters).map((e)=>{
      return filters[e]=false
    })
    setFilters({...filtersFalse,[name]:true})
   }
  return <main>
    <div className='header'>
      <h1>Lista przesyłek</h1>
      <div>
        <AllButton setChecked={checkFilter} checked={filters.all} />
        <OnWayButton setChecked={checkFilter} checked={filters.onWay} />
        <DeliveredButton setChecked={checkFilter} checked={filters.delivered} />
      </div>
    </div>
    <ShipmentTable data={filteredData} />
    <p>Prace wykonał: JA</p>
  </main>
}

export default App;
