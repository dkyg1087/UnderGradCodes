from locust import HttpUser, task

class  QuickstartUser(HttpUser):
    @task
    def get_main(self):
        userID="376033ee-519d-11eb-ac55-000c29af2c3a"
        self.client.get('/query_driver/'+userID,verify=False)