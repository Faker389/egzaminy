import { Table } from "react-bootstrap";

export default function ShipmentTable({data}){
    return (
        <Table striped bordered hover>
          <thead>
            <tr>
              <th>ID</th>
              <th>Tracking</th>
              <th>Nadawca</th>
              <th>Odbiorca</th>
              <th>Miasto</th>
              <th>Waga</th>
              <th>Status</th>
              <th>ETA</th>
            </tr>
          </thead>
          <tbody>
            {data&&data.map((e,idx)=>{
                return <tr key={idx}>
                    <td>{e.id}</td>
                    <td>{e.trackingNumber}</td>
                    <td>{e.sender}</td>
                    <td>{e.recipient}</td>
                    <td>{e.city}</td>
                    <td>{e.weightKg} kg</td>
                    <td>{e.status}</td>
                    <td>{e.eta}</td>
                </tr>
            })}
          </tbody>
        </Table>
      );
}